// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "S1/Public/S1GameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeS1GameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
S1_API UClass* Z_Construct_UClass_AS1GameModeBase();
S1_API UClass* Z_Construct_UClass_AS1GameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_S1();
// End Cross Module References

// Begin Class AS1GameModeBase
void AS1GameModeBase::StaticRegisterNativesAS1GameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AS1GameModeBase);
UClass* Z_Construct_UClass_AS1GameModeBase_NoRegister()
{
	return AS1GameModeBase::StaticClass();
}
struct Z_Construct_UClass_AS1GameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "S1GameModeBase.h" },
		{ "ModuleRelativePath", "Public/S1GameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AS1GameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AS1GameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_S1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AS1GameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AS1GameModeBase_Statics::ClassParams = {
	&AS1GameModeBase::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AS1GameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AS1GameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AS1GameModeBase()
{
	if (!Z_Registration_Info_UClass_AS1GameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AS1GameModeBase.OuterSingleton, Z_Construct_UClass_AS1GameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AS1GameModeBase.OuterSingleton;
}
template<> S1_API UClass* StaticClass<AS1GameModeBase>()
{
	return AS1GameModeBase::StaticClass();
}
AS1GameModeBase::AS1GameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AS1GameModeBase);
AS1GameModeBase::~AS1GameModeBase() {}
// End Class AS1GameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AS1GameModeBase, AS1GameModeBase::StaticClass, TEXT("AS1GameModeBase"), &Z_Registration_Info_UClass_AS1GameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AS1GameModeBase), 316555610U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameModeBase_h_2528345542(TEXT("/Script/S1"),
	Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
