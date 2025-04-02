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

#ifdef JG_ENABLE_ASSERTS
	#define JG_ASSERT(x, ...) { if(!(x)) { JG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define JG_CORE_ASSERT(x, ...) { if(!(x)) { JG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define JG_ASSERT(x, ...)
	#define JG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)