#include "Lumen.h"

using namespace Lumen;

Console::Console(const std::string &context_name)
	: m_context(new Core::Console(context_name.c_str()))
{
	m_context->Info("Console context initialized");
}

Console::~Console()
{
	m_context->Info("Console context destroyed");
	delete m_context;
}

void Console::Info(const std::string &output)
{
	m_context->Info(output.c_str());
}
