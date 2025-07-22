// Fill out your copyright notice in the Description page of Project Settings.


#include "InfodemicDb_Neo4j_Subsystem.h"

#include <cwctype>

#include "InfodemicNeo4jConnector.h"
#include "Neo4j_Connector.h"
#include "db/InfodemicDbSubsystem.h"

void UInfodemicDb_Neo4j_Subsystem::PostLoad()
{
	Super::PostLoad();
	UE_LOG(InfodemicNeo4jConnector, Display, TEXT("PostLoad"));
}

void UInfodemicDb_Neo4j_Subsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(InfodemicNeo4jConnector, Display, TEXT("Initializing"));

	Config = {};
	Config.Load();
}


void UInfodemicDb_Neo4j_Subsystem::BuildHeaders(TMap<FString, FString>& Header, bool bAccessModeWrite)
{
	Header.Emplace("Accept", "application/json");
	Header.Emplace("Content-Type", "application/json");
	Header.Emplace("Access-Mode", bAccessModeWrite ? "WRITE" : "READ");
}

FString UInfodemicDb_Neo4j_Subsystem::FormatQueries(const TArray<FString>& Queries)
{
	FString StatementStrings = "";
	TArray<FString> QueryStrings = {};
	for (int i = 0; i < Queries.Num(); i++)
	{
		FText Suffix = FText::FromString(i < Queries.Num() - 1 ? ", " : "");
		FText EscapedQuery = FText::FromString(EscapeJsonString(Queries[i]));

		static const FTextFormat StatementFormat =
			FTextFormat::FromString(" `{ \"statement\": \"{Query}\" `}{Suffix} ");
		StatementStrings += FText::FormatNamed(StatementFormat,
		                                       TEXT("Query"), EscapedQuery,
		                                       TEXT("Suffix"), Suffix
		).ToString();
	}

	static const FTextFormat Format = FTextFormat::FromString(
		"`{ \"statements\": [{Statements}] `}");
	FString Body = FText::FormatNamed(Format, TEXT("Statements"), FText::FromString(StatementStrings)).ToString();

	return Body;
}

FString UInfodemicDb_Neo4j_Subsystem::EscapeJsonString(const FString& Query)
{
	FString EscapedQuery = Query.Replace(TEXT("\""), TEXT("'"));
	EscapedQuery = EscapedQuery.Replace(TEXT("\n"), TEXT(""));

	return EscapedQuery;
}

void UInfodemicDb_Neo4j_Subsystem::PrintResponse(const FString& ResponseContent, bool bSuccess)
{
	if (!bSuccess)
	{
		UE_LOG(InfodemicNeo4jConnector, Warning, TEXT("%s"), *ResponseContent);
		return;
	}

	UE_LOG(InfodemicNeo4jConnector, Display, TEXT("%s"), *ResponseContent);
}

void UInfodemicDb_Neo4j_Subsystem::SendQueries(const TArray<FString>& Queries, bool bAccessModeWrite) const
{
	TMap<FString, FString> Headers = {};
	BuildHeaders(Headers, bAccessModeWrite);

	UNeo4j_Connector* Connection = UNeo4j_Connector::CreateREST_API_ConnectionObject_NoRequest(
		Config.Username,
		Config.Password,
		Config.Url,
		"POST",
		Headers,
		FormatQueries(Queries)
	);

	Connection->StartRequest();
}


void UInfodemicDb_Neo4j_Subsystem::Ping() const
{
	UE_LOG(InfodemicNeo4jConnector, Display, TEXT("PONG!"));
}

void UInfodemicDb_Neo4j_Subsystem::PurgeDb() const
{
	FDbCallback Callback = {};
	SendQueries({"match (n) DETACH DELETE n"}, true);
}

FText FormatPropertyName(const FName &PropertyName)
{
	check(PropertyName.GetStringLength() > 0);
	
	auto Tmp = PropertyName.ToString().GetCharArray();
	Tmp[0] = std::towlower(Tmp[0]);

	return FText::FromString(Tmp.GetData());
}

FString UInfodemicDb_Neo4j_Subsystem::CreateNodePropertyString(UIDS_Node* Node)
{
	FString PropertyStr = "";
	for (FProperty* CurrentProperty = Node->GetClass()->PropertyLink; CurrentProperty; CurrentProperty =
	     CurrentProperty->PropertyLinkNext)
	{
		const FString FieldName = CurrentProperty->GetFName().ToString();
		UE_LOG(InfodemicNeo4jConnector, Display, TEXT("CurrentField: %s"), *FieldName);
		if (!CurrentProperty->HasMetaData(TEXT("Category")))
		{
			UE_LOG(InfodemicNeo4jConnector, Display,
			       TEXT("Field '%s' doesn't have a Category Tag. Skipping Field!"), *FieldName);
			continue;
		}

		const FString& Category = CurrentProperty->GetMetaData(TEXT("Category"));
		if (!Category.Equals("Property"))
		{
			UE_LOG(InfodemicNeo4jConnector, Display,
			       TEXT("Field '%s' is not part of the Category 'Property'. Skipping Field!"), *FieldName);
			continue;
		}

		const FString Prefix = PropertyStr.IsEmpty() ? "" : ", ";

		if (auto Int64Property = CastField<FInt64Property>(CurrentProperty); Int64Property != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("'%s' is int64"), *FieldName);

			void* PropertyAddress = Int64Property->ContainerPtrToValuePtr<void>(Node);
			const int64 FieldValue = Int64Property->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString("{Prefix}{FieldName}: {FieldValue}");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FText::FromString(FString::FromInt(FieldValue)))
				.ToString();
		}
		else if (auto Int32Property = CastField<FIntProperty>(CurrentProperty); Int32Property != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("'%s' is int32"), *FieldName);

			void* PropertyAddress = Int32Property->ContainerPtrToValuePtr<void>(Node);
			const int32 FieldValue = Int32Property->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString("{Prefix}{FieldName}: {FieldValue}");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FText::FromString(FString::FromInt(FieldValue)))
				.ToString();
		}
		else if (auto FloatProperty = CastField<FFloatProperty>(CurrentProperty); Int32Property != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("'%s' is float"), *FieldName);

			void* PropertyAddress = FloatProperty->ContainerPtrToValuePtr<void>(Node);
			const float FieldValue = FloatProperty->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString("{Prefix}{FieldName}: {FieldValue}");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FText::FromString(FString::FromInt(FieldValue)))
				.ToString();
		}
		else if (auto DoubleProperty = CastField<FDoubleProperty>(CurrentProperty); Int32Property != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("'%s' is double"), *FieldName);

			void* PropertyAddress = DoubleProperty->ContainerPtrToValuePtr<void>(Node);
			const double FieldValue = DoubleProperty->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString("{Prefix}{FieldName}: {FieldValue}");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FText::FromString(FString::FromInt(FieldValue)))
				.ToString();
		}
		else if (auto StringProperty = CastField<FStrProperty>(CurrentProperty); StringProperty != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("%s: is a string"), *FieldName);
			void* PropertyAddress = StringProperty->ContainerPtrToValuePtr<void>(Node);
			const FString FieldValue = StringProperty->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString(
				"{Prefix}{FieldName}: '{FieldValue}'");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FText::FromString(FieldValue))
				.ToString();
		}
		else if (auto TextProperty = CastField<FTextProperty>(CurrentProperty); TextProperty != nullptr)
		{
			UE_LOG(InfodemicNeo4jConnector, Display, TEXT("%s: is a text"), *FieldName);

			void* PropertyAddress = TextProperty->ContainerPtrToValuePtr<void>(Node);
			const FText FieldValue = TextProperty->GetPropertyValue(PropertyAddress);

			static const FTextFormat TextValueFormat = FTextFormat::FromString(
				"{Prefix}{FieldName}: '{FieldValue}'");
			PropertyStr += FText::FormatNamed(TextValueFormat,
			                                  TEXT("Prefix"), FText::FromString(Prefix),
			                                  TEXT("FieldName"), FormatPropertyName(CurrentProperty->NamePrivate),
			                                  TEXT("FieldValue"), FieldValue)
				.ToString();
		}
		else
		{
			UE_LOG(InfodemicNeo4jConnector, Warning, TEXT("%s: is an unsupported type. Skipping field"),
			       *FieldName);
		}
	}

	return "{ " + PropertyStr + " }";
}

FString UInfodemicDb_Neo4j_Subsystem::CreateNodeTypeString(UIDS_Node* Node)
{
	TSet<FString> NodeTypes = {};
	for (auto Type : Node->GetNodeTypes())
	{
		TArray<FString> Parts = {};
		Type.ToString().ParseIntoArray(Parts, TEXT("."), false);
		NodeTypes.Append(Parts);
	}
	NodeTypes.Remove("Node");

	return FString::Join(NodeTypes, TEXT(":"));
}

FString UInfodemicDb_Neo4j_Subsystem::ExtractNodeId(UIDS_Node* Node)
{
	const FProperty* NodeIdProperty = Node->GetClass()->FindPropertyByName(TEXT("NodeId"));
	check(NodeIdProperty != nullptr);
	
	const FStrProperty* StrProperty = CastField<FStrProperty>(NodeIdProperty);
	check(StrProperty != nullptr);

	const void* PropertyAddress = StrProperty->ContainerPtrToValuePtr<void>(Node);
	FString NodeId = StrProperty->GetPropertyValue(PropertyAddress);

	return NodeId;
}

FText UInfodemicDb_Neo4j_Subsystem::ExtractRelationName(UIDS_Relation* Relation)
{
	const FProperty* RelationNameProperty = Relation->GetClass()->FindPropertyByName(TEXT("RelationName"));
	check(RelationNameProperty != nullptr);
	
	const FTextProperty* StrProperty = CastField<FTextProperty>(RelationNameProperty);
	check(StrProperty != nullptr);

	const void* PropertyAddress = StrProperty->ContainerPtrToValuePtr<void>(Relation);
	FText RelationName = StrProperty->GetPropertyValue(PropertyAddress);

	return RelationName;
}

void UInfodemicDb_Neo4j_Subsystem::AddNodeCreationQueries(TArray<FString> &Queries, TSet<UIDS_Node*> &Nodes) 
{
	for (const auto Node : Nodes)
	{
		FText NodeTypeStr = FText::FromString(CreateNodeTypeString(Node));
		FText PropertyStr = FText::FromString(CreateNodePropertyString(Node));

		static const FTextFormat QueryFormat = FTextFormat::FromString("MERGE (x:{NodeTypes} {Properties})");
		FString Query = FText::FormatNamed(QueryFormat,
		                                   TEXT("NodeTypes"), NodeTypeStr,
		                                   TEXT("Properties"),PropertyStr
		).ToString();

		Queries.Add(Query);
	}
}

void UInfodemicDb_Neo4j_Subsystem::AddRelationCreationQueries(TArray<FString> &Queries, TSet<FIDS_Information> &Information)
{
	for(const auto CurrentInformation : Information)
	{
		FText StartNodeId = FText::FromString(ExtractNodeId(CurrentInformation.StartNode));
		FText EndNodeId = FText::FromString(ExtractNodeId(CurrentInformation.EndNode));
		FText RelationName = ExtractRelationName(CurrentInformation.Relation);

		static const FTextFormat RelationQueryFormat = FTextFormat::FromString(
			"MATCH (a `{ nodeId: '{NodeA}'`}) MATCH (b `{ nodeId: '{NodeB}'`}) MERGE (a)-[:{Relation}]->(b)"
		);
		
		FString Query = FText::FormatNamed(RelationQueryFormat,
		                                   TEXT("NodeA"), StartNodeId,
		                                   TEXT("NodeB"), EndNodeId,
		                                   TEXT("Relation"), RelationName
		).ToString();

		Queries.Add(Query);
	}
}

void UInfodemicDb_Neo4j_Subsystem::PersistBundle(const UIDS_InformationBundle* Bundle) const
{
	TArray<FString> Queries = {"MATCH (n) DETACH DELETE n"};
	TSet<UIDS_Node*> Nodes = {};
	TSet<FIDS_Information> Information = {};
	
	for (const auto CurrentInformation : Information)
	{
		Information.Add(CurrentInformation);
		Nodes.Add(CurrentInformation.StartNode);
		Nodes.Add(CurrentInformation.EndNode);
	}

	AddNodeCreationQueries(Queries, Nodes);
	AddRelationCreationQueries(Queries, Information);
	
	SendQueries(Queries, true);
}

void UInfodemicDb_Neo4j_Subsystem::PersistCollection(UIDS_InformationCollection* Collection) const
{
	TArray<FString> Queries = {"MATCH (n) DETACH DELETE n"};
	TSet<UIDS_Node*> Nodes = {};
	TSet<FIDS_Information> Information = {};
	Collection->UpdateCombinedInformationCollection();

	for(const auto Bundle : Collection->GetCombinedInformationCollection())
	{
		for(const auto CurrentInformation : Bundle->GetInformation())
		{
			Information.Add(CurrentInformation);
			Nodes.Add(CurrentInformation.StartNode);
			Nodes.Add(CurrentInformation.EndNode);
		}
	}

	AddNodeCreationQueries(Queries, Nodes);
	AddRelationCreationQueries(Queries, Information);

	SendQueries(Queries, true);
}
