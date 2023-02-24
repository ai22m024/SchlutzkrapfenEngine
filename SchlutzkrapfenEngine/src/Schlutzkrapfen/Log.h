#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>
namespace Schlutzkrapfen{
	class SK_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logger macros
#define SK_CORE_TRACE(...)	::Schlutzkrapfen::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SK_CORE_INFO(...)	::Schlutzkrapfen::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SK_CORE_WARN(...)	::Schlutzkrapfen::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SK_CORE_ERROR(...)	::Schlutzkrapfen::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SK_CORE_FATAL(...)	::Schlutzkrapfen::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLient logger macros
#define SK_TRACE(...)		::Schlutzkrapfen::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SK_INFO(...)		::Schlutzkrapfen::Log::GetClientLogger()->info(__VA_ARGS__)
#define SK_WARN(...)		::Schlutzkrapfen::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SK_ERROR(...)		::Schlutzkrapfen::Log::GetClientLogger()->error(__VA_ARGS__)
#define SK_FATAL(...)		::Schlutzkrapfen::Log::GetClientLogger()->fatal(__VA_ARGS__)
