#include "eng_pch.h"
#include "EngCore\Platform\Win\WindowWin.h"

namespace EngX {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowWin(props);
	}

	WindowWin::WindowWin(const WindowProps& props)
	{
		Init(props);
	}

	WindowWin::~WindowWin()
	{
		Shutdown();
	}

	void WindowWin::Init(const WindowProps& props)
	{
		windowData.Title = props.Title;
		windowData.Width = props.Width;
		windowData.Height = props.Height;

		EX_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			EX_CORE_ASSERT(success, "Could not intialize GLFW!");

			s_GLFWInitialized = true;
		}

		Window = glfwCreateWindow((int)props.Width, (int)props.Height, windowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, &windowData);
		SetVSync(true);
	}

	void WindowWin::Shutdown()
	{
		glfwDestroyWindow(Window);
	}

	void WindowWin::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(Window);
	}

	void WindowWin::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		windowData.VSync = enabled;
	}

	bool WindowWin::IsVSync() const
	{
		return windowData.VSync;
	}

}