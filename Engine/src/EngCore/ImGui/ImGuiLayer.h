#pragma once

#include <EngCore\Layers\Layer.h>
#include "EngCore\Events\KeyEvent.h"
#include "EngCore\Events\MouseEvent.h"
#include "EngCore\Events\ApplicationEvent.h"


namespace EngX {

	struct EX_API ImGuiLayer : Layer
	{
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;

		virtual void OnImGuiRender() override;

		void BeginFrame();
		void EndFrame();

		float workingTime_ { 0.0f };
	};

}