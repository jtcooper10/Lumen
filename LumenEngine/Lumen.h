#pragma once

#include "LumenCore.h"
#include <string>

namespace Lumen
{
	class Console
	{
	public:
		Console(const std::string &context_name);
		~Console();

		void Info(const std::string &output);

	private:
		Core::Console *m_context;
	};

	struct LUMEN_API Application
	{

	private:
		Core::Application *m_context;
	};
}
