#pragma once

#ifdef _WIN32
#	ifdef LUMEN_DLL_BUILD
#		define LUMEN_API __declspec(dllexport)
#	else
#		define LUMEN_API __declspec(dllimport)
#	endif
#endif


namespace Lumen
{
	namespace Core
	{
		class LoggingContext;

		extern "C"
		{
			LoggingContext LUMEN_API *liblmConsole_Create(const char *context_name);
			void LUMEN_API liblmConsole_Destroy(LoggingContext **context);
			void LUMEN_API liblmConsole_LogInfo(const LoggingContext *context, const char *output);
			void LUMEN_API liblmConsole_LogWarn(const LoggingContext *context, const char *output);
			void LUMEN_API liblmConsole_LogError(const LoggingContext *context, const char *output);
			void LUMEN_API liblmConsole_LogCrit(const LoggingContext *context, const char *output);
		}
	}
}
