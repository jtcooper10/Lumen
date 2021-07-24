#include "Lumen.h"


Lumen::Console::Console(const std::string &context_name)
	: m_context(Lumen::Core::liblmConsole_Create(context_name.c_str()))
{}

Lumen::Console::~Console()
{
	Lumen::Core::liblmConsole_Destroy(&m_context);
}

Lumen::Application::Application(
	unsigned int window_width,
	unsigned int window_height,
	const std::string &window_title)
	: m_context(Lumen::Core::liblmApplication_Create(
			window_width, window_height, window_title.c_str())),
	  m_geometry(Lumen::Core::liblmApplication_CreateGeometry(m_context)),
	  console(window_title)
{ }

Lumen::Application::~Application()
{
	Lumen::Core::liblmApplication_DestroyGeometry(m_context, &m_geometry);
	Lumen::Core::liblmApplication_Destroy(&m_context);
}

bool Lumen::Application::Draw()
{
	return Lumen::Core::liblmApplication_DrawGeometry(m_context, m_geometry);
}
