#include "LumenCore.h"
#include "LoggingContext.h"
#include "ApplicationContext.h"
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace Lumen::Core;


LoggingContext *Lumen::Core::liblmConsole_Create(const char *context_name)
{
	return new LoggingContext(std::string(context_name));
}

void Lumen::Core::liblmConsole_Destroy(LoggingContext **context)
{
	delete *context;
	*context = nullptr;
}

void Lumen::Core::liblmConsole_LogInfo(const LoggingContext *context, const char *output)
{
	context->LogInfo(std::string(output));
}
void Lumen::Core::liblmConsole_LogWarn(const LoggingContext *context, const char *output)
{
	context->LogWarn(std::string(output));
}
void Lumen::Core::liblmConsole_LogError(const LoggingContext *context, const char *output)
{
	context->LogError(std::string(output));
}
void Lumen::Core::liblmConsole_LogCrit(const LoggingContext *context, const char *output)
{
	context->LogCrit(std::string(output));
}


ApplicationContext *Lumen::Core::liblmApplication_Create(
	unsigned int window_width,
	unsigned int window_height,
	const char *window_title)
{
	if (!glfwInit())
	{
		LoggingContext::CoreCrit("GLFW failed to initialize");
		return nullptr;
	}

	GLFWwindow *context_window = glfwCreateWindow(
		window_width, window_height,
		window_title,
		nullptr, nullptr);
	if (!context_window)
	{
		LoggingContext::CoreError("Failed to create GLFW window: " + std::string(window_title));
		return nullptr;
	}
	glfwMakeContextCurrent(context_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LoggingContext::CoreError("Failed to create OpenGL context: " + std::string(window_title));
		return nullptr;
	}

	return new ApplicationContext(context_window);
}

void Lumen::Core::liblmApplication_Destroy(ApplicationContext **context)
{
	delete *context;
	*context = nullptr;
}

int Lumen::Core::liblmApplication_Draw(ApplicationContext *context)
{
	return context->Draw();
}

int Lumen::Core::liblmApplication_DrawGeometry(ApplicationContext *context, Geometry *geometry)
{
	return context->Draw(geometry);
}

Geometry *Lumen::Core::liblmApplication_CreateGeometry(ApplicationContext *context)
{
	Geometry *geometry;
	unsigned int vertex_id;
	unsigned int index_id;

	glGenBuffers(1, &vertex_id);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_id);

	glGenBuffers(1, &index_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id);

	geometry = new Geometry {
		{ -0.5f, -0.5f, 0.0f,
		  -0.5f,  0.5f, 0.0f,
		   0.5f,  0.5f, 0.0f,
		   0.5f, -0.5f, 0.0f },
		{ 0, 1, 2, 0, 2, 3 }
	};
	geometry->vertex_id = vertex_id;
	geometry->index_id = index_id;
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, &geometry->data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * 6, &geometry->index, GL_STATIC_DRAW);

	return geometry;
}

void Lumen::Core::liblmApplication_DestroyGeometry(ApplicationContext *context, Geometry **geometry)
{
	delete *geometry;
	*geometry = nullptr;
}
