#pragma once

#include "EngCore\Core.h"

namespace EngX {

	struct EX_API Input
	{
		using pos2d = std::pair<float, float>;
		inline static bool IsKeyPressed(int keyCode) { return instance_->IsKeyPressedImpl_(keyCode); };

		inline static bool IsMouseButtonPressed(int button) { return instance_->IsMouseButtonPressedImpl_(button); };
		inline static pos2d GetMousePosition() { return instance_->GetMousePositionImpl(); };
		inline static float GetMouseX() { return instance_->GetMouseXImpl_(); };
		inline static float GetMouseY() { return instance_->GetMouseYImpl_(); };
		

		virtual bool IsKeyPressedImpl_(int keyCode) = 0;
		virtual bool IsMouseButtonPressedImpl_(int button) = 0;
		virtual float GetMouseXImpl_() = 0;
		virtual float GetMouseYImpl_() = 0;
		virtual pos2d GetMousePositionImpl() = 0;

		static Input* instance_;
	};
}