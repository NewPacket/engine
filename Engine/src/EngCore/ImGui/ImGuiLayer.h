#pragma once

#include <EngCore\Layers\Layer.h>
#include "EngCore\Events\KeyEvent.h"
#include "EngCore\Events\MouseEvent.h"
#include "EngCore\Events\ApplicationEvent.h"


namespace EngX {

	struct EX_API ImGuiLayer : Layer
	{
		ImGuiLayer();
		virtual ~ImGuiLayer();


		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

		float workingTime{ 0.0f };
	};

}