#pragma once

#include "Core.h"

namespace EngX {

	struct EX_API App
	{
		App();
		int Run();

		virtual ~App();
	};

	App* CreateApp();
}

