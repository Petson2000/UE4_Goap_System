// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Goap_System : ModuleRules
{
	public Goap_System(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
