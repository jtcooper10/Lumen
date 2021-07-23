// RenderingEngine.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace LibRenderer
{
	class LoggingContext
	{
	public:
		enum class LogLevel
		{
			TRACE = 0,
			INFO,
			WARN,
			ERR,
			CRIT
		};

		static void LogInit();
		static void SetLogLevel(LogLevel log_level);

		inline static void LogInfo(const std::string& output)
		{
			LoggingContext::Core()->info(output);
		}

		inline static void LogWarn(const std::string& output)
		{
			LoggingContext::Core()->warn(output);
		}

		inline static void LogError(const std::string& output)
		{
			LoggingContext::Core()->error(output);
		}

		inline static void LogCritical(const std::string& output)
		{
			LoggingContext::Core()->critical(output);
		}

		inline static std::shared_ptr<spdlog::logger> Core()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger> Client()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

	using LogLevel = LoggingContext::LogLevel;
}
