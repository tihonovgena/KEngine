#pragma once



/*
* Core macros library
*/

// TODO easyreadable file to add macros includes
#ifdef KE_PLATFORM_WINDOWS

	#ifdef KE_BUILD_DLL
		#define KENGINE_API __declspec(dllexport)
	#else
		#define KENGINE_API __declspec(dllimport)
	#endif // KE_BUILD_DLL

#else 
	#error KEngine support only Windows

#endif // KE_PLATFORM_WINDOWS
