using UnrealBuildTool;
using System.Collections.Generic;

public class NonogramEditorTarget
	: TargetRules
{
	public NonogramEditorTarget(TargetInfo target)
		: base(target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "Nonogram" });
	}
}