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


		class ApplicationContext;
		struct Geometry;

		struct Position
		{
			const float x;
			const float y;
			const float z;
		};

		extern "C"
		{
			ApplicationContext LUMEN_API *liblmApplication_Create(
				unsigned int window_width,
				unsigned int window_height,
				const char *window_title);
			void LUMEN_API liblmApplication_Destroy(ApplicationContext **context);
			int LUMEN_API liblmApplication_Draw(ApplicationContext *context);

			Geometry LUMEN_API *liblmApplication_CreateGeometry(ApplicationContext *context);
			void LUMEN_API liblmApplication_DestroyGeometry(ApplicationContext *context, Geometry **geometry);
			int LUMEN_API liblmApplication_DrawGeometry(ApplicationContext *context, Geometry *geometry);

			//void LUMEN_API liblmGeometry_SetPosition(Geometry *geometry, Position position);
			//void LUMEN_API liblmGeometry_SetSize(Geometry *geometry, unsigned int width, unsigned int height);
		}
	}
}
