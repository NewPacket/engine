#pragma once
#include "EngCore\Log.h"
#include "EngCore\Events\ApplicationEvent.h"
#include "EngCore\Core.h"
#include "EngCore\Window.h"

namespace EngX {

	struct EX_API App
	{
		App();
		int Run();

		virtual ~App();
	};

	App* CreateApp();

	std::unique_ptr<Window> windowHandle;
	bool running{ true };
}

