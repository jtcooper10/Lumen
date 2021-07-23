#include "RenderEngine.h"
#include "RenderEngine.h"
#include "RenderEngine.h"
#include "RenderEngine.h"
#include "LoggingContext.h"

#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>

using namespace LibRenderer;

static std::unique_ptr<std::vector<GLFWwindow*>> context_collection;
static int context_count = 0;

RenderEngine::RenderEngine()
{
	LoggingContext::LogInfo("Render Engine has been initialized.");
}


ApplicationContext::ApplicationContext(const int context_id)
	: m_context_id(context_id)
{
	// Empty constructor body
}

ApplicationContext::~ApplicationContext()
{
	if (context_collection->at(m_context_id))
	{
		glfwDestroyWindow(context_collection->at(m_context_id));
		glfwTerminate();
	}
}

ApplicationContext* ApplicationContext::CreateContext(
	int window_width,
	int window_height,
	const char const* window_name)
{
	// TODO: enforce thread safety concerns
	// 1) Assert that CreateContext() and DeleteContext()
	//   are ALWAYS called on the main thread.
	// 2) Find a better way than a static vector to represent abstract window handles.
	// Context collection starts un-initialized.
	// A nullptr indicates the collection has not yet been initialized.
	if (!context_collection)
	{
		context_collection = std::make_unique<std::vector<GLFWwindow*>>();
		LoggingContext::LogInit();
	}

	// Note: multiple calls to glfwInit() are allowed.
	// Successive calls to glfwInit() return TRUE immediately.
	// https://www.glfw.org/docs/latest/intro_guide.html#intro_init_init
	if (!glfwInit())
	{
		LoggingContext::LogError("Could not initialize GLFW.");
	}
	else
	{
		LoggingContext::LogInfo("GLFW context initialized.");
	}

	GLFWwindow* context_window = glfwCreateWindow(
		window_width,
		window_height,
		window_name,
		nullptr, nullptr);
	if (context_window)
	{
		context_collection->push_back(context_window);
		LoggingContext::LogInfo("GLFW window initialized.");
	}
	else
	{
		LoggingContext::LogError("GLFW window could not be initialized.");
	}

	// `context_count` represents the ID of the "next" window to create.
	// As such, the current value of `context_count` represents the context's ID.
	return new ApplicationContext(context_count++);
}

void LibRenderer::ApplicationContext::DeleteContext(ApplicationContext* context)
{
	context_collection->at(context->m_context_id) = nullptr;
	delete context;
}

void LibRenderer::ApplicationContext::MakeCurrent()
{
	glfwMakeContextCurrent(context_collection->at(m_context_id));
}

int LibRenderer::ApplicationContext::PollContent()
{
	return !glfwWindowShouldClose(context_collection->at(m_context_id));
}

void LibRenderer::ApplicationContext::PollEvents()
{
	glfwSwapBuffers(context_collection->at(m_context_id));
	glfwPollEvents();
}


void Console::LogInfo(const std::string& message)
{
	LoggingContext::Client()->info(message);
}

void Console::LogWarn(const std::string& message)
{
	LoggingContext::Client()->warn(message);
}

void Console::LogError(const std::string& message)
{
	LoggingContext::Client()->error(message);
}

void Console::LogCrit(const std::string& message)
{
	LoggingContext::Client()->critical(message);
}
