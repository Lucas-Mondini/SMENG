#pragma once

#ifdef SEG_PLATAFORM_WINDOWS
	#ifdef SEG_BUILD_DLL
		#define SMENG_API __declspec(dllexport)
	#else
		#define SMENG_API __declspec(dllimport)
	#endif
#else
#error non suported plataform
#endif 
