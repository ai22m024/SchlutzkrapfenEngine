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