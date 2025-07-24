# InfodemicSystemPlugin
The InfodemicSystemPlugin (also referenced as InfodemicDB) is approaching to define a knowledge graph using Unreal Engine 5 DataAssets, which can be stored in a graph database like Neo4j.

## Supported Databases
- Neo4j

## How information is being persisted
The main data types if InfodemicDB are
- IDS_Node,
- IDS_Relation,
- IDS_Information (struct),
- IDS_InformationBundle,
- and IDS_InformationCollection

![InfodemicDB_ClassDiagram](https://github.com/user-attachments/assets/d443260d-184e-4c7f-b749-13499bda102b)

### IDS_Node
https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/base/nodes/IDS_Node.h

An IDS_Node is a PrimaryDataAsset which represents a unique node in a property knowledge graph. The IDS_Node class only contains a id and nodeType attribute, but the class can be extended to add more properties.
The node types are being set via the nodeTypes GameplayTagContainer, while each tag and parent tag is being translated into its own types, while the root tag is being ignored. For example, if a BlackSmith node has the "Knowledge.Profession.Smith" type, 
then the BlackSmith node has the distinct node types "Profession" and "Smith".

<img width="533" height="416" alt="node-data-asset" src="https://github.com/user-attachments/assets/12324840-d2a4-49ed-87e9-067cb1f2951b" />
<img width="252" height="205" alt="node-data-asset-files" src="https://github.com/user-attachments/assets/9eb3d745-ded1-4217-8c86-839afc9cfe1c" />

### IDS_Relation
https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/base/IDS_Relation.h

Relation are being defined via the IDS_Relation data asset. It consists of the RelationName, used as the name inside database and a start- and end node type used for defining defining compatible node types.
> Node: Relations with properties are currently not supported!
 
<img width="528" height="331" alt="image" src="https://github.com/user-attachments/assets/a7b4fff2-7b3b-4dd8-bfcd-569c483cc9e1" />
<img width="366" height="190" alt="image" src="https://github.com/user-attachments/assets/aa388399-4b58-4bf3-a398-87b19f110a3c" />

### IDS_Information
https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/base/IDS_Information.h

An IDS_Information is a struct representing an information triplet, consisting of a start node, a relation and an end node. An information can consist of a single start node without a relation or end node.
On the validation process of an asset containing this struct, the start and end note types are being compared to the types defined in the used relation.
The type tags are only valid if one of its assigned node are either an exact match or are a child tag of the relation type, otherwise an error message is thrown. For example, the relation type "Knowledge.Place" accepts all Nodes of the type
"Knowledge.Place" and its child tags like "Knowledge.Place.Village". However, if the relation type requires "Knowledge.Place.Village", then assigning a node of type "Knowledge.Place" throws an error.

### IDS_InformationBundle
https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/base/IDS_InformationBundle.h

An Information bundle is here defined as the smallest possible set of information triplets, which are required to represent a complex information.
An InformationBundle could for example define multiple members of a family, without defining the entire family tree.
By calling the "LoadIntoDB" function (also available as a button) the bundle can be loaded into the configured graph database.
> Note: LoadIntoDb deletes all data in the database before inserting the data from this bundle.
> LoadIntoDB should only be used for debugging purpouses to validate, the integrity of the generated database entites and relations.

To make InformationBundles more managable they can be categorized via GameplayTags (see [AssetTagSubject](https://github.com/tortle-sh/AssetTagTreePlugin#AssetTagSubject)).

<img width="864" height="707" alt="image" src="https://github.com/user-attachments/assets/8d082f20-57d8-4b0b-80b2-974a2a7885c5" />
<img width="914" height="592" alt="image" src="https://github.com/user-attachments/assets/2821c02f-cb00-4633-ba19-b88322653c76" />

### IDS_InformationCollection
https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/base/IDS_InformationCollection.h

An information collection persists all information bundles which are relevant in a specific knowledge domain. If the InformationCollection is used to represent 
the entire knowledge base of a specific character, it contains all InformationBundles/all the knowledge that the charater should have access to.
Similarly to the InformationBundle, the collection can be persisted in a given graph database using the "LoadIntoDb" function/button in order to query all the knowledge the character has acces to, via cypher queries.
> Note: LoadIntoDb deletes all data in the database before inserting the data from this collection, to ensure that only the currently relevant information is accessible.

It is also possible to import categorized information bundles (see [AssetTagObserver](https://github.com/tortle-sh/AssetTagTreePlugin#AssetTagObserver)). By default importing bundles from a category also imports all bundles from its parent categories, 
since child categories are here being interpreted as specializations of knowledge domains. 

<img width="962" height="560" alt="image" src="https://github.com/user-attachments/assets/c0f84941-21e6-4b5f-aaa6-c9ee7adba5e7" />

## Category Initialization
In order to use the categorization system, all information bundles and collections have to be automatically loaded during the start of the engine, using the either [uInfodemicAssetManager](https://github.com/tortle-sh/InfodemicSystemPlugin/blob/master/Source/InfodemicCore/Public/InfodemicAssetManager.h), or a custom AssetManager which does the same (see https://dev.epicgames.com/documentation/en-us/unreal-engine/asset-management-in-unreal-engine)












 
