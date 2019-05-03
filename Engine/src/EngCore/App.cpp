#include "eng_pch.h"
#include "App.h"

namespace EngX {

	App::App()
	{
		Log::Init();
		windowHandle = std::unique_ptr<Window>(Window::Create());
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
			windowHandle->OnUpdate();
		}
		return 0;
	}
}
