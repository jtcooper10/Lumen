#include <iostream>
#include "RenderEngine.h"

int main()
{
	LibRenderer::ApplicationContext *context
		= LibRenderer::ApplicationContext::CreateContext(720, 480, "My Engine 1");

	while (context->PollContent())
	{
		context->PollEvents();
	}

	LibRenderer::ApplicationContext::DeleteContext(context);
	return 0;
}
