#pragma once

#include <string>

#include "LumenCore.h"

// Forward declaration of GLFW structure
// Allows us to force GLAD/GLFW include order (GLAD must be included)
struct GLFWwindow;

namespace Lumen
{
	namespace Core
	{

		struct Geometry
		{
			float data[12];
			unsigned int index[6];
			unsigned int vertex_id;
			unsigned int index_id;
		};

		class ApplicationContext
		{
		public:
			ApplicationContext(GLFWwindow *window);
			bool Draw();
			bool Draw(Geometry *geometry);

		private:
			GLFWwindow *m_window;
		};
	}
}
