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

#define LShiftbit(x) (1 << x)