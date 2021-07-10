#pragma once

#include <string>

#ifdef _WIN32
#	ifdef RND_DLL_BUILD
#		define RND_API __declspec(dllexport)
#	else
#		define RND_API __declspec(dllimport)
#	endif
#endif

namespace LibRenderer
{

	class RND_API Console
	{
	public:
		void LogInfo(const std::string& message);
		void LogWarn(const std::string& message);
		void LogError(const std::string& message);
		void LogCrit(const std::string& message);
	};

	class RND_API RenderEngine
	{
	public:
		RenderEngine();
	};

	class RND_API ApplicationContext
	{
	public:
		Console console;
		RenderEngine engine;

		~ApplicationContext();

		void MakeCurrent();
		int PollContent();
		void PollEvents();

		static ApplicationContext* CreateContext(
			int window_width,
			int window_height,
			const char const* window_name);

		static void DeleteContext(ApplicationContext* context);

	private:
		const int m_context_id;
		ApplicationContext(const int context_id);
		ApplicationContext() = delete;
	};

}
