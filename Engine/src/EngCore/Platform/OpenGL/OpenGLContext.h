#pragma once
#include "EngCore\Renderer\GraphicsContext.h"

struct GLFWwindow;

namespace EngX {

	struct OpenGLContext : GraphicsContext {

		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

		GLFWwindow* windowHandle_;
	};
}