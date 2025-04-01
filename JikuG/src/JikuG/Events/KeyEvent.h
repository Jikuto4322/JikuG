#pragma once

#include "Event.h"

namespace JikuG {

	class JIKUG_API KeyPressedEvent : public Event
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: m_KeyCode(keycode), m_RepeatCount(repeatCount) {
		}

		inline int GetKeyCode() const { return m_KeyCode; }
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	private:
		int m_KeyCode;
		int m_RepeatCount;
	};

	class JIKUG_API KeyReleasedEvent : public Event
	{
	public:
		KeyReleasedEvent(int keycode)
			: m_KeyCode(keycode) {
		}

		inline int GetKeyCode() const { return m_KeyCode; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	private:
		int m_KeyCode;
	};
}
