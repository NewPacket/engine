#pragma once
#include "EngCore\Core.h"
#include "EngCore\Events\Event.h"

#include <string>

namespace EngX {

	struct WindowProps
	{
		std::string Title;
		uint16_t Width;
		uint16_t Height;

		WindowProps(const std::string& title = "XEngine",
			uint16_t wigth = 1280, uint16_t height = 720)
			: Title(std::move(title)), Width(wigth), Height(height)
		{}

	};

	struct EX_API Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;
		
		virtual uint16_t GetWidth() const = 0;
		virtual uint16_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}