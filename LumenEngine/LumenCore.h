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
		struct LUMEN_API ILoggingContext
		{
			virtual void LogInfo(const char *message) = 0;
			virtual void LogWarn(const char *message) = 0;
			virtual void LogError(const char *message) = 0;
			virtual void LogCrit(const char *message) = 0;
		};

		extern "C"
		{
			ILoggingContext LUMEN_API *CreateLoggingContext(const char *context_name);
			void LUMEN_API DestroyLoggingContext(ILoggingContext *context);
		}
	}
}
