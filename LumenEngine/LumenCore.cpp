#include "LumenCore.h"
#include "LoggingContext.h"
#include "ApplicationContext.h"
#include <string>

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
