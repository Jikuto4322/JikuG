#pragma once

#ifdef JG_PLATFORM_WINDOWS
	#ifdef JG_BUILD_DLL
		#define JIKUG_API __declspec(dllexport)
	#else
		#define JIKUG_API __declspec(dllimport)
	#endif
#else
	#error JikuG only supports Windows!
#endif

#define BIT(x) (1 << x)