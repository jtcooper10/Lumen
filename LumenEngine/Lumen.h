#pragma once

#include "LumenCore.h"
#include <string>
#include <memory>

namespace Lumen
{
	class Console
	{
	public:
		Console(const std::string &context_name);
		Console(const Console &console) = delete;
		~Console();
		inline void Info(const std::string &output)
		{
			Lumen::Core::liblmConsole_LogInfo(m_context, output.c_str());
		}
		inline void Warn(const std::string &output)
		{
			Lumen::Core::liblmConsole_LogWarn(m_context, output.c_str());
		}
		inline void Error(const std::string &output)
		{
			Lumen::Core::liblmConsole_LogError(m_context, output.c_str());
		}
		inline void Crit(const std::string &output)
		{
			Lumen::Core::liblmConsole_LogCrit(m_context, output.c_str());
		}

	private:
		Core::LoggingContext *m_context;
	};

	class Application
	{
	public:
		Console console;

		Application(
			unsigned int window_width,
			unsigned int window_height,
			const std::string &window_title);
		Application(const Application &application) = delete;
		~Application();

		bool Draw();

	private:
		Core::ApplicationContext *m_context;
	};
}
