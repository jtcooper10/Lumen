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
		// Forward declaration of internal library classes
		class LoggingContext;
		class ApplicationContext;

		struct LUMEN_API Console
		{
		public:
			Console(const char *context_name);
			Console(const Console &console) = delete;
			~Console();
			void Info(const char *message);
			void Warn(const char *message);
			void Error(const char *message);
			void Crit(const char *message);

		private:
			LoggingContext *lib_context;
		};

		struct LUMEN_API Application
		{
		public:

		private:
			ApplicationContext *lib_context;
		};
	}
}
