#pragma once

#ifdef EX_PLATFORM_WIN
#if EX_DYNAMIC_LIB
	#ifdef EX_BUILD_DLL
		#define EX_API __declspec(dllexport)
	#else
		#define EX_API __declspec(dllimport)
	#endif
#else 
	#define EX_API
#endif
#else

	#error Only for Win
#endif

#ifdef EX_ENABLE_ASSERTS
	#define EX_ASSERT(x, ...) { if(!(x))	  { EX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define EX_CORE_ASSERT(x, ...) { if(!(x)) { EX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define EX_ASSERT(x, ...)
	#define EX_CORE_ASSERT(x, ...)
#endif

#define EX_BIND_TYPE_EVENT_FN(type, fn) [this](type& e){ return fn(e); }
#define BIT(x) (1 << x)