#pragma once

#include "spch.h"

#ifdef SEG_PLATAFORM_WINDOWS
	#ifdef SEG_BUILD_DLL
		#define SMENG_API __declspec(dllexport)
	#else
		#define SMENG_API __declspec(dllimport)
	#endif
#else
#error non suported plataform
#endif 

#ifdef SMENG_ENABLE_ASSERTS
	#define SMG_ASSERT(x, ...) { if(!x){SMENG_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SMG_CORE_ASSERT(x, ...) { if(!x){SMENG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SMG_ASSERT(x, ...)
	#define SMG_CORE_ASSERT(x, ...) 
#endif



#define LShiftbit(x) (1 << x)