#pragma once
#include "EngCore\Core.h"
#include "EngCore\Events\Event.h"

namespace EngX {

	struct EX_API Layer
	{
		Layer(const std::string& name = "Layer") : debugName(std::move(name)) {};
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};
		virtual void OnImGuiRender() {};

		inline const std::string& DbgGetName() const { return debugName; }

		std::string debugName;

	};

}