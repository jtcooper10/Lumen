// RenderingEngine.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

#include "LumenCore.h"

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

			LoggingContext(const std::string &context_name);

			static void LogInit();
			static void SetLogLevel(LogLevel log_level);

			inline static std::shared_ptr<spdlog::logger> Core() { return s_core_logger; }
			inline static void CoreInfo(const std::string &output) { LoggingContext::Core()->info(output); }
			inline static void CoreWarn(const std::string &output) { LoggingContext::Core()->warn(output); }
			inline static void CoreError(const std::string &output) { LoggingContext::Core()->error(output); }
			inline static void CoreCrit(const std::string &output) { LoggingContext::Core()->critical(output); }

			inline std::shared_ptr<spdlog::logger> Client() const { return m_logger; }
			void LogInfo(const std::string &output) const;
			void LogWarn(const std::string &output) const;
			void LogError(const std::string &output) const;
			void LogCrit(const std::string &output) const;

		private:
			static std::shared_ptr<spdlog::logger> s_core_logger;
			std::shared_ptr<spdlog::logger> m_logger;
		};
	}
}
