#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace SMENG {
	class SMENG_API Log
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

//Core Log Macros
#define SMENG_CORE_FATAL(...)	::SMENG::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define SMENG_CORE_ERROR(...)	::SMENG::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SMENG_CORE_WARN(...)	::SMENG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SMENG_CORE_INFO(...)	::SMENG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SMENG_CORE_TRACE(...)	::SMENG::Log::GetCoreLogger()->trace(__VA_ARGS__)


//Client Log Macros
#define SMENG_CLIENT_FATAL(...)	::SMENG::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define SMENG_CLIENT_ERROR(...)	::SMENG::Log::GetClientLogger()->error(__VA_ARGS__)
#define SMENG_CLIENT_WARN(...)	::SMENG::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SMENG_CLIENT_INFO(...)	::SMENG::Log::GetClientLogger()->info(__VA_ARGS__)
#define SMENG_CLIENT_TRACE(...)	::SMENG::Log::GetClientLogger()->trace(__VA_ARGS__)