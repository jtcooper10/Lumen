// RenderingEngine.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Lumen
{
	namespace Core
	{
		class LoggingContext
		{
		public:
			const std::string context_name;

			enum class LogLevel
			{
				TRACE = 0,
				INFO,
				WARN,
				ERR,
				CRIT
			};

			LoggingContext(const char *const name);

			static void LogInit();
			static void SetLogLevel(LogLevel log_level);

			inline static std::shared_ptr<spdlog::logger> Core() { return s_core_logger; }
			inline static void CoreInfo(const std::string &output) { LoggingContext::Core()->info(output); }
			inline static void CoreWarn(const std::string &output) { LoggingContext::Core()->warn(output); }
			inline static void CoreError(const std::string &output) { LoggingContext::Core()->error(output); }
			inline static void CoreCrit(const std::string &output) { LoggingContext::Core()->critical(output); }

			inline std::shared_ptr<spdlog::logger> Client() { return m_logger; }
			inline void LogInfo(const std::string &output) { Client()->info(output); }
			inline void LogWarn(const std::string &output) { Client()->warn(output); }
			inline void LogError(const std::string &output) { Client()->error(output); }
			inline void LogCrit(const std::string &output) { Client()->critical(output); }

		private:
			static std::shared_ptr<spdlog::logger> s_core_logger;
			std::shared_ptr<spdlog::logger> m_logger;
		};

		using LogLevel = LoggingContext::LogLevel;
	}
}
