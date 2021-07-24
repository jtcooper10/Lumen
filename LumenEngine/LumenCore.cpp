#include "LumenCore.h"
#include "LoggingContext.h"
#include "ApplicationContext.h"
#include <string>

using namespace Lumen::Core;


LoggingContext *Lumen::Core::liblmConsole_Create(const char *context_name)
{
	return new LoggingContext(std::string(context_name));
}

void Lumen::Core::liblmConsole_Destroy(LoggingContext **context)
{
	delete *context;
	context = nullptr;
}

void Lumen::Core::liblmConsole_LogInfo(const LoggingContext *context, const char *output)
{
	context->LogInfo(std::string(output));
}
void Lumen::Core::liblmConsole_LogWarn(const LoggingContext *context, const char *output)
{
	context->LogWarn(std::string(output));
}
void Lumen::Core::liblmConsole_LogError(const LoggingContext *context, const char *output)
{
	context->LogError(std::string(output));
}
void Lumen::Core::liblmConsole_LogCrit(const LoggingContext *context, const char *output)
{
	context->LogCrit(std::string(output));
}
