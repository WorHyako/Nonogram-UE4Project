using UnrealBuildTool;

public class Nonogram : ModuleRules
{
	public Nonogram(ReadOnlyTargetRules target)
		: base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}