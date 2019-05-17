#pragma once

namespace EngX {

	struct GraphicsContext {


		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

	};

}