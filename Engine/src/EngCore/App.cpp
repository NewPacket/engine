#include "eng_pch.h"
#include "App.h"

#include <glad\glad.h>
#include <imgui.h>

namespace EngX {

	App* App::appInstance_ = nullptr;

	App::App()
	{
		EX_CORE_ASSERT(appInstance_ == nullptr,"App instance already created");
		Log::Init();
		windowHandle_ = std::unique_ptr<Window>(Window::Create());
		windowHandle_->SetEventCallback([this](Event& e) { OnEvent(e); });
		appInstance_ = this;

		imguiLayer_ = new ImGuiLayer();
		PushOverLay(imguiLayer_);
	}


	App::~App()
	{
	}


	int App::Run() 
	{
		WindowResizeEvent e {1200, 720};
		EX_TRACE("{0}",e);
		while (running_)
		{
			glClearColor(0,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack_)
				layer->OnUpdate();

			imguiLayer_->BeginFrame();
			ImGui::Text("Hello World");
			for (Layer* layer : layerStack_)
				layer->OnImGuiRender();

			imguiLayer_->EndFrame();

			windowHandle_->OnUpdate();
		}
		return 0;
	}

	void App::PushLayer(Layer* layer)
	{
		layerStack_.PushLayer(layer);
		layer->OnAttach();
	}


	void App::PushOverLay(Layer* overlay)
	{
		layerStack_.PushOverlay(overlay);
		overlay->OnAttach();
	}


	void App::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent & e) {return OnWindowCloseEvent(e); });

		for (auto it = layerStack_.end(); it != layerStack_.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.isHandled)
				break;
		};


		EX_CORE_TRACE("{0}", e);
	}


	bool App::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		running_ = false;
		return true;
	}
}
