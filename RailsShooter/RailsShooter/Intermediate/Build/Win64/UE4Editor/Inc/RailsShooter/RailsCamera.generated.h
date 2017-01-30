// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RAILSSHOOTER_RailsCamera_generated_h
#error "RailsCamera.generated.h already included, missing '#pragma once' in RailsCamera.h"
#endif
#define RAILSSHOOTER_RailsCamera_generated_h

#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_RPC_WRAPPERS
#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_EVENT_PARMS \
	struct RailsCamera_eventGetCameraOrthoHeight_Parms \
	{ \
		float ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		RailsCamera_eventGetCameraOrthoHeight_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	}; \
	struct RailsCamera_eventGetCameraOrthoWidth_Parms \
	{ \
		float ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		RailsCamera_eventGetCameraOrthoWidth_Parms() \
			: ReturnValue(0) \
		{ \
		} \
	};


extern RAILSSHOOTER_API  FName RAILSSHOOTER_GetCameraOrthoHeight;
extern RAILSSHOOTER_API  FName RAILSSHOOTER_GetCameraOrthoWidth;
#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_CALLBACK_WRAPPERS
#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesARailsCamera(); \
	friend RAILSSHOOTER_API class UClass* Z_Construct_UClass_ARailsCamera(); \
	public: \
	DECLARE_CLASS(ARailsCamera, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RailsShooter"), NO_API) \
	DECLARE_SERIALIZER(ARailsCamera) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesARailsCamera(); \
	friend RAILSSHOOTER_API class UClass* Z_Construct_UClass_ARailsCamera(); \
	public: \
	DECLARE_CLASS(ARailsCamera, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RailsShooter"), NO_API) \
	DECLARE_SERIALIZER(ARailsCamera) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARailsCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARailsCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARailsCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARailsCamera); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ARailsCamera(const ARailsCamera& InCopy); \
public:


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ARailsCamera(const ARailsCamera& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARailsCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARailsCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARailsCamera)


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_8_PROLOG \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_EVENT_PARMS


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_RPC_WRAPPERS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_CALLBACK_WRAPPERS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_INCLASS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_CALLBACK_WRAPPERS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_INCLASS_NO_PURE_DECLS \
	RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RailsShooter_Source_RailsShooter_Cameras_RailsCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
