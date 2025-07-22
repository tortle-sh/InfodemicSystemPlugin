#include "InfodemicNeo4jConnector.h"

#define LOCTEXT_NAMESPACE "FInfodemicNeo4jConnectorModule"

DEFINE_LOG_CATEGORY(InfodemicNeo4jConnector)

void FInfodemicNeo4jConnectorModule::StartupModule()
{
	UE_LOG(InfodemicNeo4jConnector, Display, TEXT("Module loaded"))
    
}

void FInfodemicNeo4jConnectorModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FInfodemicNeo4jConnectorModule, InfodemicNeo4jConnector)