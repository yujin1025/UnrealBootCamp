// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSampleChat_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SampleChat;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SampleChat()
	{
		if (!Z_Registration_Info_UPackage__Script_SampleChat.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SampleChat",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x302B8F86,
				0x60128984,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SampleChat.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SampleChat.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SampleChat(Z_Construct_UPackage__Script_SampleChat, TEXT("/Script/SampleChat"), Z_Registration_Info_UPackage__Script_SampleChat, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x302B8F86, 0x60128984));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
