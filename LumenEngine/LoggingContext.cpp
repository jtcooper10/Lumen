// RenderingEngine.cpp : Defines the entry point for the application.
//

#include "LoggingContext.h"
#include <iostream>

using namespace Lumen::Core;


std::shared_ptr<spdlog::logger> LoggingContext::s_core_logger;

void LoggingContext::LogInit()
{
	if (!LoggingContext::s_core_logger)
	{
		LoggingContext::s_core_logger = spdlog::stdout_color_mt("ENGINE");
		LoggingContext::CoreInfo("Logging context initialized");
	}
}

void LoggingContext::SetLogLevel(LoggingContext::LogLevel log_level)
{
	spdlog::level::level_enum s_level = spdlog::level::trace;

	switch (log_level)
	{
	case LoggingContext::LogLevel::INFO:
		s_level = spdlog::level::info; break;
	case LoggingContext::LogLevel::WARN:
		s_level = spdlog::level::warn; break;
	case LoggingContext::LogLevel::ERR:
		s_level = spdlog::level::err; break;
	case LoggingContext::LogLevel::CRIT:
		s_level = spdlog::level::critical; break;
	case LoggingContext::LogLevel::TRACE:
		s_level = spdlog::level::trace; break;
	}

	spdlog::set_level(s_level);
}

LoggingContext::LoggingContext(const std::string &name)
	: context_name(name)
{
	LoggingContext::LogInit();
	m_logger = spdlog::stdout_color_mt(context_name);
}

void LoggingContext::LogInfo(const char *output)
{
	Client()->info(output);
}

void LoggingContext::LogWarn(const char *output)
{
	Client()->warn(output);
}

void LoggingContext::LogError(const char *output)
{
	Client()->error(output);
}

void LoggingContext::LogCrit(const char *output)
{
	Client()->critical(output);
}
