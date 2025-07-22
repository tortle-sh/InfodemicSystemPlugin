using UnrealBuildTool;

public class InfodemicNeo4jConnector : ModuleRules
{
    public InfodemicNeo4jConnector(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "InfodemicCore",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "BA_Neo4j",
                "InfodemicCore"
            }
        );
    }
}