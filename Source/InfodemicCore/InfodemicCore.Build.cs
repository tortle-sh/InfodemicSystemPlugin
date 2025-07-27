using UnrealBuildTool;

public class InfodemicCore : ModuleRules
{
    public InfodemicCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", 
                "AssetTagTreeRuntime",
                "DataValidation"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "GameplayTags",
                "UnrealEd",
            }
        );
    }
}