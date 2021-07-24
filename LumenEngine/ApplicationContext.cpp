#include "ApplicationContext.h"
#include "LoggingContext.h"

using namespace Lumen::Core;

ApplicationContext::ApplicationContext(GLFWwindow *window)
	: m_window(window)
{ }

bool ApplicationContext::Draw()
{
	if (glfwWindowShouldClose(m_window))
	{
		return false;
	}

	glfwSwapBuffers(m_window);
	glfwPollEvents();
	return true;
}
