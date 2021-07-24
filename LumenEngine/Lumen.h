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
}
