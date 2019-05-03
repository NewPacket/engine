#pragma once
#include "EngCore\Log.h"
#include "EngCore\Core.h"
#include "EngCore\Window.h"
#include "EngCore\Layers\LayerStack.h"
#include "EngCore\Events\ApplicationEvent.h"

namespace EngX {

	struct EX_API App
	{
		App();
		virtual ~App();

		int Run();

		void OnEvent(Event&);
		bool OnWindowCloseEvent(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* overlay);

		LayerStack layerStack;
	};

	App* CreateApp();

	std::unique_ptr<Window> windowHandle;
	bool running{ true };
}

