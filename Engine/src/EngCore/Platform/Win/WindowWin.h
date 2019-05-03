#pragma once
#pragma once

#include "EngCore/Window.h"
#include <GLFW/glfw3.h>

namespace EngX {

	struct WindowWin : Window
	{

		WindowWin(const WindowProps& props);
		virtual ~WindowWin();

		void OnUpdate() override;

		inline uint16_t GetWidth() const override { return windowData.Width; }
		inline uint16_t GetHeight() const override { return windowData.Height; }


		virtual void SetEventCallback(const EventCallbackFn& callback) override { windowData.EventCallback = callback; }
		void SetVSync(bool enabled) override;

		bool IsVSync() const override;

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* Window;

		struct WindowData
		{
			std::string Title;
			uint16_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData windowData;
	};

}