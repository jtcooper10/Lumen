#include "ApplicationContext.h"
#include "LoggingContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(m_window);
	glfwPollEvents();

	return true;
}

bool ApplicationContext::Draw(Geometry *geometry)
{
	if (glfwWindowShouldClose(m_window))
	{
		return false;
	}

	glfwPollEvents();

	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, geometry->vertex_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->index_id);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	glfwSwapBuffers(m_window);

	return true;
}
