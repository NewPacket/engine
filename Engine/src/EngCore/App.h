#pragma once
#include "EngCore\Core.h"
#include "EngCore\Window.h"
#include "EngCore\Layers\LayerStack.h"
#include "EngCore\Events\ApplicationEvent.h"

#include "ImGui\ImGuiLayer.h"

namespace EngX {

	struct EX_API App
	{
		App();
		virtual ~App();

		int Run();

		void OnEvent(Event&);

		inline static App& App::AppRef() { return *appInstance_; };
		inline Window& WindowRef() { return *windowHandle_; };

		bool OnWindowCloseEvent(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);

		static App* appInstance_;
		std::unique_ptr<Window> windowHandle_;

		

		bool running_{ true };
		LayerStack layerStack_;
		ImGuiLayer* imguiLayer_;
	};

	App* CreateApp();
	

}

