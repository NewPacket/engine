#pragma once

#include "EngCore\Window.h"
#include "EngCore\Renderer\GraphicsContext.h"

struct GLFWwindow;

namespace EngX {

	struct WindowWin : Window
	{

		WindowWin(const WindowProps& props);
		virtual ~WindowWin();

		void OnUpdate() override;

		inline uint16_t GetWidth() const override { return windowData_.width; }
		inline uint16_t GetHeight() const override { return windowData_.height; }

		inline void* GetNativeWindow() const { return window_; };

		virtual void SetEventCallback(const EventCallbackFn& callback) override { windowData_.EventCallback = callback; }
		void SetVSync(bool enabled) override;

		bool IsVSync() const override;

		virtual void Init_(const WindowProps& props);
		virtual void Shutdown_();

		

		struct WindowData
		{
			std::string title;
			uint16_t width, height;
			bool VSync;

			EventCallbackFn EventCallback;
		} windowData_;

		GLFWwindow* window_;
		GraphicsContext* context_;
	};

}