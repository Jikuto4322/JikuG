#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"
#include "spdlog\fmt\ostr.h"

namespace JikuG {
	class Log
	{
	public:
		static JIKUG_API void Init();

		inline JIKUG_API static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline JIKUG_API static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static JIKUG_API std::shared_ptr<spdlog::logger> s_CoreLogger;
		static JIKUG_API std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define JG_CORE_ERROR(...)	::JikuG::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JG_CORE_INFO(...)	::JikuG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JG_CORE_TRACE(...)	::JikuG::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JG_CORE_WARN(...)	::JikuG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JG_CORE_FATAL(...)	::JikuG::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define JG_ERROR(...)		::JikuG::Log::GetClientLogger()->error(__VA_ARGS__)
#define JG_INFO(...)		::JikuG::Log::GetClientLogger()->info(__VA_ARGS__)
#define JG_TRACE(...)		::JikuG::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JG_WARN(...)		::JikuG::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JG_FATAL(...)		::JikuG::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dist build, disable all logs
