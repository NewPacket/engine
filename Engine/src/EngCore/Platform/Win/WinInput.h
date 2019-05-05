#pragma once
#include "EngCore\Input.h"

namespace EngX {

	struct EX_API WinInput : Input 
	{
		

		virtual bool  IsKeyPressedImpl_			(int keyCode) override;

		virtual bool  IsMouseButtonPressedImpl_	(int button)  override;
		virtual pos2d GetMousePositionImpl		()		      override;
		virtual float GetMouseXImpl_			()			  override;
		virtual float GetMouseYImpl_			()			  override;
	};

}