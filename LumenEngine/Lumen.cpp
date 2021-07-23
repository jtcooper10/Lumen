#include "Lumen.h"

using namespace Lumen;

Console::Console(const std::string &context_name)
	: m_context(context_name.c_str())
{
	m_context.Info("Console context initialized");
}

void Console::Info(const std::string &output)
{
	m_context.Info(output.c_str());
}

void Console::Warn(const std::string &output)
{
	m_context.Warn(output.c_str());
}

void Console::Error(const std::string &output)
{
	m_context.Error(output.c_str());
}

void Console::Crit(const std::string &output)
{
	m_context.Crit(output.c_str());
}
