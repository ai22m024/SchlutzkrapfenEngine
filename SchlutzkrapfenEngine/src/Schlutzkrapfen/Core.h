#pragma once

#ifdef SK_PLATFORM_WINDOWS
#ifdef SK_BUILD_DLL
#define SK_API __declspec(dllexport)
#else
#define SK_API __declspec(dllimport)
#endif
#else
#error Schlutzkrapfen only taste good on Windows.
#endif

#ifdef  SK_ENABLE_ASSERTS
#define SK_ASSERT(x, ...) { if(!(x)) {HZ_ERROR("Cooking failed: {0}", __VA_ARGS__); __debugbreak();}}
#define SK_CORE_ASSERT(x, ...) { if(!(x)) {HZ_CORE_ERROR("Cooking failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define SK_ASSERT(x, ...)
#define SK_CORE_ASSERT(x, ...)

#endif


#define BIT(x) (1 << x)