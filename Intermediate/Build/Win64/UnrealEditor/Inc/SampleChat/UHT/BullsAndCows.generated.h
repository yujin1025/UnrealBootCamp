// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BullsAndCows.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAMPLECHAT_BullsAndCows_generated_h
#error "BullsAndCows.generated.h already included, missing '#pragma once' in BullsAndCows.h"
#endif
#define SAMPLECHAT_BullsAndCows_generated_h

#define FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execValidatePlayerNumber); \
	DECLARE_FUNCTION(execCheckBullsAndCows); \
	DECLARE_FUNCTION(execGenerateRandomNumber);


#define FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBullsAndCows(); \
	friend struct Z_Construct_UClass_UBullsAndCows_Statics; \
public: \
	DECLARE_CLASS(UBullsAndCows, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SampleChat"), NO_API) \
	DECLARE_SERIALIZER(UBullsAndCows)


#define FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBullsAndCows(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UBullsAndCows(UBullsAndCows&&); \
	UBullsAndCows(const UBullsAndCows&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBullsAndCows); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBullsAndCows); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBullsAndCows) \
	NO_API virtual ~UBullsAndCows();


#define FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_7_PROLOG
#define FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_INCLASS_NO_PURE_DECLS \
	FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAMPLECHAT_API UClass* StaticClass<class UBullsAndCows>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BootCamp_SampleChat_SampleChat_Source_SampleChat_BullsAndCows_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
