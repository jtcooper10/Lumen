#include "LumenCore.h"
#include "LoggingContext.h"
#include "ApplicationContext.h"
#include <string>

using namespace Lumen::Core;


ILoggingContext *Lumen::Core::CreateLoggingContext(const char *context_name)
{
	return new LoggingContext(std::string(context_name));
}

void Lumen::Core::DestroyLoggingContext(ILoggingContext *context)
{
	delete context;
}
