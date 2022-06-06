// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameEon_Ass_Loco : ModuleRules
{
	public GameEon_Ass_Loco(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" }); //Put UMG to display Widget
	}
}
