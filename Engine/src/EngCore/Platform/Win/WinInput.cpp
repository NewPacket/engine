#include "eng_pch.h"
#include "WinInput.h"

#include "GLFW\glfw3.h"
#include "EngCore\App.h"


namespace EngX {

	Input* Input::instance_ = new WinInput();

	bool WinInput::IsKeyPressedImpl_(int keyCode)
	{
		auto  window = static_cast<GLFWwindow*>( App::AppRef().WindowRef().GetNativeWindow());

		auto state = glfwGetKey(window, keyCode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WinInput::IsMouseButtonPressedImpl_(int button)
	{
		auto  window = static_cast<GLFWwindow*>(App::AppRef().WindowRef().GetNativeWindow());

		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	using pos2d = std::pair<float, float>;
	pos2d WinInput::GetMousePositionImpl()
	{
		auto  window = static_cast<GLFWwindow*>(App::AppRef().WindowRef().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		return pos2d{ (float) x, (float) y };
	}

	float WinInput::GetMouseXImpl_()
	{
		auto [x, y] = GetMousePositionImpl();
		return (float)x;
	}

	float WinInput::GetMouseYImpl_()
	{
		auto [x, y] = GetMousePositionImpl();
		return (float)y;
	}
}


