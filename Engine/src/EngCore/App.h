#pragma once
#include "EngCore\Log.h"
#include "EngCore\Events\ApplicationEvent.h"
#include "EngCore\Core.h"

namespace EngX {

	struct EX_API App
	{
		App();
		int Run();

		virtual ~App();
	};

	App* CreateApp();
}

