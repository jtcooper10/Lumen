#include <iostream>
#include "Lumen.h"

using namespace Lumen::Core;

int main()
{
	LoggingContext *context = liblmConsole_Create("TESTING");
	liblmConsole_LogInfo(context, "Hello, world!");

	return 0;
}
