#pragma once

#include "LumenCore.h"
#include <string>

namespace Lumen
{
	class Console
	{
	public:
		Console(const std::string &context_name);

		void Info(const std::string &output);
		void Warn(const std::string &output);
		void Error(const std::string &output);
		void Crit(const std::string &output);

	private:
		Core::Console m_context;
	};

	class Application
	{

	private:
		Core::Application m_context;
	};
}
