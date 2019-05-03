#pragma once

#include "Event.h"

//#include <sstream>

namespace EngX {

	struct EX_API KeyEvent : Event
	{
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	struct EX_API KeyPressedEvent : KeyEvent
	{
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

		int m_RepeatCount;
	};

	struct EX_API KeyReleasedEvent : KeyEvent
	{
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}