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
		inline void Info(const std::string &output) { m_context->LogInfo(output.c_str()); }
		inline void Warn(const std::string &output) { m_context->LogWarn(output.c_str()); }
		inline void Error(const std::string &output) { m_context->LogError(output.c_str()); }
		inline void Crit(const std::string &output) { m_context->LogCrit(output.c_str()); }

	private:
		std::unique_ptr<Core::ILoggingContext> m_context;
	};
}
