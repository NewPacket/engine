#include "App.h"


namespace EngX {

	App::App()
	{
	}


	App::~App()
	{
	}

	int App::Run() 
	{
		Log::Init();
		WindowResizeEvent e {1200, 720};
		EX_TRACE(e);
		while (true)
		{
		}
	}
}
