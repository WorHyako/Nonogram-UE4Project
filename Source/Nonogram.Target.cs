using UnrealBuildTool;
using System.Collections.Generic;

public class NonogramTarget
	: TargetRules
{
	public NonogramTarget(TargetInfo target)
		: base(target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "Nonogram" });
	}
}