#include "eng_pch.h"
#include "App.h"

#include <glad\glad.h>

namespace EngX {

	App::App()
	{
		Log::Init();
		windowHandle = std::unique_ptr<Window>(Window::Create());
		windowHandle->SetEventCallback([this](Event& e) { OnEvent(e); });
	}


	App::~App()
	{
	}


	int App::Run() 
	{
		WindowResizeEvent e {1200, 720};
		EX_TRACE(e);
		while (running)
		{
			glClearColor(0,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			windowHandle->OnUpdate();
		}
		return 0;
	}

	void App::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}


	void App::PushOverLay(Layer* overlay)
	{
		layerStack.PushOverlay(overlay);
	}


	void App::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent & e) {return OnWindowCloseEvent(e); });

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.isHandled)
				break;
		};


		EX_CORE_TRACE("{0}", e);
	}


	bool App::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		running = false;
		return true;
	}
}
