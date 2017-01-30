// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef RAILSSHOOTER_Bullet_generated_h
#error "Bullet.generated.h already included, missing '#pragma once' in Bullet.h"
#endif
#define RAILSSHOOTER_Bullet_generated_h

#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_RPC_WRAPPERS \
	virtual void DestroyMeNow_Implementation(); \
 \
	DECLARE_FUNCTION(execDestroyMeNow_Implementation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DestroyMeNow_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyMeNow) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DestroyMeNow_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDestroyMeNow_Implementation) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DestroyMeNow_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDestroyMeNow) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DestroyMeNow_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapEnd) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnOverlapBegin) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_EVENT_PARMS
extern RAILSSHOOTER_API  FName RAILSSHOOTER_DestroyMeNow;
#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_CALLBACK_WRAPPERS
#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABullet(); \
	friend RAILSSHOOTER_API class UClass* Z_Construct_UClass_ABullet(); \
	public: \
	DECLARE_CLASS(ABullet, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RailsShooter"), NO_API) \
	DECLARE_SERIALIZER(ABullet) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesABullet(); \
	friend RAILSSHOOTER_API class UClass* Z_Construct_UClass_ABullet(); \
	public: \
	DECLARE_CLASS(ABullet, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RailsShooter"), NO_API) \
	DECLARE_SERIALIZER(ABullet) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABullet(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABullet) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABullet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABullet); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABullet(const ABullet& InCopy); \
public:


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABullet(const ABullet& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABullet); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABullet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABullet)


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_8_PROLOG \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_EVENT_PARMS


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_RPC_WRAPPERS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_CALLBACK_WRAPPERS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_INCLASS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_CALLBACK_WRAPPERS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_INCLASS_NO_PURE_DECLS \
	RailsShooter_Source_RailsShooter_Targets_Bullet_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RailsShooter_Source_RailsShooter_Targets_Bullet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS