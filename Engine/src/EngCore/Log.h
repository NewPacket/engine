#pragma once

#include "EngCore\Core.h"
#include <spdlog\spdlog.h>
#include "spdlog\fmt\ostr.h"

//#include <memory>

namespace EngX {

	struct EX_API Log
	{
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return core_logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return client_logger; }

		static std::shared_ptr<spdlog::logger> core_logger;
		static std::shared_ptr<spdlog::logger> client_logger;
	};

}

// Core log macros
#define EX_CORE_FATAL(...)   ::EngX::Log::GetCoreLogger()->critical(__VA_ARGS__);
#define EX_CORE_ERROR(...)   ::EngX::Log::GetCoreLogger()->error(__VA_ARGS__);
#define EX_CORE_WARN(...)    ::EngX::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define EX_CORE_INFO(...)    ::EngX::Log::GetCoreLogger()->info(__VA_ARGS__);
#define EX_CORE_TRACE(...)   ::EngX::Log::GetCoreLogger()->trace(__VA_ARGS__);

// Client log macros
#define EX_FATAL(...)        ::EngX::Log::GetClientLogger()->critical(__VA_ARGS__);
#define EX_ERROR(...)        ::EngX::Log::GetClientLogger()->error(__VA_ARGS__);
#define EX_WARN(...)         ::EngX::Log::GetClientLogger()->warn(__VA_ARGS__);
#define EX_INFO(...)         ::EngX::Log::GetClientLogger()->info(__VA_ARGS__);
#define EX_TRACE(...)        ::EngX::Log::GetClientLogger()->trace(__VA_ARGS__);