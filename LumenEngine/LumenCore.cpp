#include "LumenCore.h"
#include "LoggingContext.h"
#include <string>

using namespace Lumen::Core;

Console::Console(const char *context_name)
	: lib_context(new LoggingContext(context_name)) {}

void Console::Init()
{
	LoggingContext::LogInit();
}

void Console::Info(const char *message)
{
	lib_context->LogInfo(std::string(message));
}

void Console::Warn(const char *message)
{
	lib_context->LogWarn(std::string(message));
}

void Console::Error(const char *message)
{
	lib_context->LogError(std::string(message));
}

void Console::Crit(const char *message)
{
	lib_context->LogCrit(std::string(message));
}
