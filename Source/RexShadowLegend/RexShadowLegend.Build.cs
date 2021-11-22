// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RexShadowLegend : ModuleRules
{
	public RexShadowLegend(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
