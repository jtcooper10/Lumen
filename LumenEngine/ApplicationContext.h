#pragma once

#include <GLFW/glfw3.h>
#include <string>

#include "LumenCore.h"

namespace Lumen
{
	namespace Core
	{
		class ApplicationContext
		{
		public:
			ApplicationContext(GLFWwindow *window);
			bool Draw();

		private:
			GLFWwindow *m_window;
		};
	}
}
