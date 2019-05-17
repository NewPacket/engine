#include "eng_pch.h"
#include "OpenGLContext.h"

#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace EngX {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : windowHandle_(windowHandle) {
		EX_CORE_ASSERT(windowHandle_, "Window Handle is null");
	};


	void OpenGLContext::Init() {
		glfwMakeContextCurrent(windowHandle_);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EX_CORE_ASSERT(status, "Failed to initialize Glad");
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(windowHandle_);
	}
}