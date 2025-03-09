// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "S1/Public/S1GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeS1GameInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
S1_API UClass* Z_Construct_UClass_US1GameInstance();
S1_API UClass* Z_Construct_UClass_US1GameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_S1();
// End Cross Module References

// Begin Class US1GameInstance Function ConnectToGameServer
struct Z_Construct_UFunction_US1GameInstance_ConnectToGameServer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/S1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_US1GameInstance_ConnectToGameServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_US1GameInstance, nullptr, "ConnectToGameServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_US1GameInstance_ConnectToGameServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_US1GameInstance_ConnectToGameServer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_US1GameInstance_ConnectToGameServer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_US1GameInstance_ConnectToGameServer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(US1GameInstance::execConnectToGameServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ConnectToGameServer();
	P_NATIVE_END;
}
// End Class US1GameInstance Function ConnectToGameServer

// Begin Class US1GameInstance Function DisconnectFromGameServer
struct Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/S1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_US1GameInstance, nullptr, "DisconnectFromGameServer", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(US1GameInstance::execDisconnectFromGameServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DisconnectFromGameServer();
	P_NATIVE_END;
}
// End Class US1GameInstance Function DisconnectFromGameServer

// Begin Class US1GameInstance Function HandleRecvPackets
struct Z_Construct_UFunction_US1GameInstance_HandleRecvPackets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/S1GameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_US1GameInstance_HandleRecvPackets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_US1GameInstance, nullptr, "HandleRecvPackets", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_US1GameInstance_HandleRecvPackets_Statics::Function_MetaDataParams), Z_Construct_UFunction_US1GameInstance_HandleRecvPackets_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_US1GameInstance_HandleRecvPackets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_US1GameInstance_HandleRecvPackets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(US1GameInstance::execHandleRecvPackets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleRecvPackets();
	P_NATIVE_END;
}
// End Class US1GameInstance Function HandleRecvPackets

// Begin Class US1GameInstance
void US1GameInstance::StaticRegisterNativesUS1GameInstance()
{
	UClass* Class = US1GameInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConnectToGameServer", &US1GameInstance::execConnectToGameServer },
		{ "DisconnectFromGameServer", &US1GameInstance::execDisconnectFromGameServer },
		{ "HandleRecvPackets", &US1GameInstance::execHandleRecvPackets },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(US1GameInstance);
UClass* Z_Construct_UClass_US1GameInstance_NoRegister()
{
	return US1GameInstance::StaticClass();
}
struct Z_Construct_UClass_US1GameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "S1GameInstance.h" },
		{ "ModuleRelativePath", "Public/S1GameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_US1GameInstance_ConnectToGameServer, "ConnectToGameServer" }, // 1420839782
		{ &Z_Construct_UFunction_US1GameInstance_DisconnectFromGameServer, "DisconnectFromGameServer" }, // 2657401167
		{ &Z_Construct_UFunction_US1GameInstance_HandleRecvPackets, "HandleRecvPackets" }, // 4279412696
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<US1GameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_US1GameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_S1,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_US1GameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_US1GameInstance_Statics::ClassParams = {
	&US1GameInstance::StaticClass,
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
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_US1GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_US1GameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_US1GameInstance()
{
	if (!Z_Registration_Info_UClass_US1GameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_US1GameInstance.OuterSingleton, Z_Construct_UClass_US1GameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_US1GameInstance.OuterSingleton;
}
template<> S1_API UClass* StaticClass<US1GameInstance>()
{
	return US1GameInstance::StaticClass();
}
US1GameInstance::US1GameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(US1GameInstance);
US1GameInstance::~US1GameInstance() {}
// End Class US1GameInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_US1GameInstance, US1GameInstance::StaticClass, TEXT("US1GameInstance"), &Z_Registration_Info_UClass_US1GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(US1GameInstance), 1200044696U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameInstance_h_3790626695(TEXT("/Script/S1"),
	Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_A_Documents_IOCP_UE5_S1_Source_S1_Public_S1GameInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
