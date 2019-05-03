#include "eng_pch.h"
#include "EngCore\Platform\Win\WindowWin.h"

#include "EngCore\Events\ApplicationEvent.h"
#include "EngCore\Events\KeyEvent.h"
#include "EngCore\Events\MouseEvent.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace EngX {

	static bool s_GLFWInitialized = false;

	static void GLFWErorrCallback(int errorCode, const char* errorDesc)
	{
		EX_CORE_ERROR("GLFW Error ( {0} : {1} )", errorCode, errorDesc);
	};

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

			glfwSetErrorCallback(GLFWErorrCallback);
			s_GLFWInitialized = true;
		}

		Window = glfwCreateWindow((int)props.Width, (int)props.Height, windowData.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EX_CORE_ASSERT(status, "Failed to initialize Glad");
		glfwSetWindowUserPointer(Window, &windowData);
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(Window, []( GLFWwindow* window, int width , int height) 
		{
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			data.EventCallback(WindowResizeEvent{ (unsigned int) width, (unsigned int) height });
		});

		glfwSetWindowCloseCallback(Window, [](GLFWwindow * window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(WindowCloseEvent());
		});

		glfwSetKeyCallback(Window, [](GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			//TODO:: Try to make it through immidiate lambda exec
			switch (action)
			{
				case GLFW_PRESS:
					data.EventCallback(KeyPressedEvent{ key, 0 });
				case GLFW_RELEASE:
					data.EventCallback(KeyReleasedEvent{ key });
				case GLFW_REPEAT:
					data.EventCallback(KeyPressedEvent{ key, 1 });
			};
		});

		glfwSetMouseButtonCallback(Window, [](GLFWwindow * window, int button, int action, int mod)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
					data.EventCallback(MouseButtonPressedEvent{ button });
				case GLFW_RELEASE:
					data.EventCallback(MouseButtonReleasedEvent{ button });
			};

		});

		glfwSetScrollCallback(Window, [](GLFWwindow * window, double xOffset, double yOffset) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(MouseScrolledEvent{ (float)xOffset, (float) yOffset});
		});

		glfwSetCursorPosCallback(Window, [](GLFWwindow * window, double xPos , double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.EventCallback(MouseMovedEvent{ (float)xPos, (float)xPos });
		});
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