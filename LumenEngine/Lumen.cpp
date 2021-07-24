#include "Lumen.h"

using namespace Lumen;


Console::Console(const std::string &context_name)
	: m_context(Core::CreateLoggingContext(context_name.c_str()))
{}
