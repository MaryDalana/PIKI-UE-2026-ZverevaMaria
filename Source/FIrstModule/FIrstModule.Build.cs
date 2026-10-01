// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FIrstModule : ModuleRules
{
	public FIrstModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FIrstModule",
			"FIrstModule/Variant_Platforming",
			"FIrstModule/Variant_Platforming/Animation",
			"FIrstModule/Variant_Combat",
			"FIrstModule/Variant_Combat/AI",
			"FIrstModule/Variant_Combat/Animation",
			"FIrstModule/Variant_Combat/Gameplay",
			"FIrstModule/Variant_Combat/Interfaces",
			"FIrstModule/Variant_Combat/UI",
			"FIrstModule/Variant_SideScrolling",
			"FIrstModule/Variant_SideScrolling/AI",
			"FIrstModule/Variant_SideScrolling/Gameplay",
			"FIrstModule/Variant_SideScrolling/Interfaces",
			"FIrstModule/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
