// RenderingEngine.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "LoggingContext.h"

using namespace LibRenderer;

std::shared_ptr<spdlog::logger> LoggingContext::s_CoreLogger;
std::shared_ptr<spdlog::logger> LoggingContext::s_ClientLogger;

void LoggingContext::LogInit()
{
	s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
	s_ClientLogger = spdlog::stdout_color_mt("CONSOLE");

	Core()->info("Console contexts have been initialized.");
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
