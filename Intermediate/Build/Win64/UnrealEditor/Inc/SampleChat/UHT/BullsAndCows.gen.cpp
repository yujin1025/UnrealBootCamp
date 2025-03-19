// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SampleChat/BullsAndCows.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBullsAndCows() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
SAMPLECHAT_API UClass* Z_Construct_UClass_UBullsAndCows();
SAMPLECHAT_API UClass* Z_Construct_UClass_UBullsAndCows_NoRegister();
UPackage* Z_Construct_UPackage__Script_SampleChat();
// End Cross Module References

// Begin Class UBullsAndCows Function CheckBullsAndCows
struct Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics
{
	struct BullsAndCows_eventCheckBullsAndCows_Parms
	{
		FString ServerNumber;
		FString PlayerNumber;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BullsAndCows" },
		{ "ModuleRelativePath", "BullsAndCows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ServerNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ServerNumber;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerNumber;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_ServerNumber = { "ServerNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BullsAndCows_eventCheckBullsAndCows_Parms, ServerNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ServerNumber_MetaData), NewProp_ServerNumber_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_PlayerNumber = { "PlayerNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BullsAndCows_eventCheckBullsAndCows_Parms, PlayerNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerNumber_MetaData), NewProp_PlayerNumber_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BullsAndCows_eventCheckBullsAndCows_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_ServerNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_PlayerNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBullsAndCows, nullptr, "CheckBullsAndCows", nullptr, nullptr, Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::BullsAndCows_eventCheckBullsAndCows_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::BullsAndCows_eventCheckBullsAndCows_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBullsAndCows::execCheckBullsAndCows)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ServerNumber);
	P_GET_PROPERTY(FStrProperty,Z_Param_PlayerNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBullsAndCows::CheckBullsAndCows(Z_Param_ServerNumber,Z_Param_PlayerNumber);
	P_NATIVE_END;
}
// End Class UBullsAndCows Function CheckBullsAndCows

// Begin Class UBullsAndCows Function GenerateRandomNumber
struct Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics
{
	struct BullsAndCows_eventGenerateRandomNumber_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BullsAndCows" },
		{ "ModuleRelativePath", "BullsAndCows.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BullsAndCows_eventGenerateRandomNumber_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBullsAndCows, nullptr, "GenerateRandomNumber", nullptr, nullptr, Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::BullsAndCows_eventGenerateRandomNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::BullsAndCows_eventGenerateRandomNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBullsAndCows::execGenerateRandomNumber)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBullsAndCows::GenerateRandomNumber();
	P_NATIVE_END;
}
// End Class UBullsAndCows Function GenerateRandomNumber

// Begin Class UBullsAndCows Function ValidatePlayerNumber
struct Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics
{
	struct BullsAndCows_eventValidatePlayerNumber_Parms
	{
		FString PlayerNumber;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BullsAndCows" },
		{ "ModuleRelativePath", "BullsAndCows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerNumber;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_PlayerNumber = { "PlayerNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BullsAndCows_eventValidatePlayerNumber_Parms, PlayerNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerNumber_MetaData), NewProp_PlayerNumber_MetaData) };
void Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BullsAndCows_eventValidatePlayerNumber_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BullsAndCows_eventValidatePlayerNumber_Parms), &Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_PlayerNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UBullsAndCows, nullptr, "ValidatePlayerNumber", nullptr, nullptr, Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::BullsAndCows_eventValidatePlayerNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::BullsAndCows_eventValidatePlayerNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBullsAndCows::execValidatePlayerNumber)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_PlayerNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBullsAndCows::ValidatePlayerNumber(Z_Param_PlayerNumber);
	P_NATIVE_END;
}
// End Class UBullsAndCows Function ValidatePlayerNumber

// Begin Class UBullsAndCows
void UBullsAndCows::StaticRegisterNativesUBullsAndCows()
{
	UClass* Class = UBullsAndCows::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CheckBullsAndCows", &UBullsAndCows::execCheckBullsAndCows },
		{ "GenerateRandomNumber", &UBullsAndCows::execGenerateRandomNumber },
		{ "ValidatePlayerNumber", &UBullsAndCows::execValidatePlayerNumber },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBullsAndCows);
UClass* Z_Construct_UClass_UBullsAndCows_NoRegister()
{
	return UBullsAndCows::StaticClass();
}
struct Z_Construct_UClass_UBullsAndCows_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BullsAndCows.h" },
		{ "ModuleRelativePath", "BullsAndCows.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBullsAndCows_CheckBullsAndCows, "CheckBullsAndCows" }, // 3108901854
		{ &Z_Construct_UFunction_UBullsAndCows_GenerateRandomNumber, "GenerateRandomNumber" }, // 333855003
		{ &Z_Construct_UFunction_UBullsAndCows_ValidatePlayerNumber, "ValidatePlayerNumber" }, // 667802673
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBullsAndCows>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UBullsAndCows_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_SampleChat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBullsAndCows_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBullsAndCows_Statics::ClassParams = {
	&UBullsAndCows::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBullsAndCows_Statics::Class_MetaDataParams), Z_Construct_UClass_UBullsAndCows_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBullsAndCows()
{
	if (!Z_Registration_Info_UClass_UBullsAndCows.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBullsAndCows.OuterSingleton, Z_Construct_UClass_UBullsAndCows_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBullsAndCows.OuterSingleton;
}
template<> SAMPLECHAT_API UClass* StaticClass<UBullsAndCows>()
{
	return UBullsAndCows::StaticClass();
}
UBullsAndCows::UBullsAndCows(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBullsAndCows);
UBullsAndCows::~UBullsAndCows() {}
// End Class UBullsAndCows

// Begin Registration
struct Z_CompiledInDeferFile_FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBullsAndCows, UBullsAndCows::StaticClass, TEXT("UBullsAndCows"), &Z_Registration_Info_UClass_UBullsAndCows, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBullsAndCows), 1753265837U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_3358716363(TEXT("/Script/SampleChat"),
	Z_CompiledInDeferFile_FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
