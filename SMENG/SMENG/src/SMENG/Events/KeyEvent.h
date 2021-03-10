#pragma once

#include "Event.h"
#include <sstream>

namespace SMENG {
	class SMENG_API KeyEvent : public Event {
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		virtual int getCategoryFlags() const override { 
			return (EventCategoryKeyboard | EventCategoryInput); 
		}
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {		
		}
		int m_KeyCode;
	};


	class SMENG_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) 
			: KeyEvent(keycode)
			, m_RepeatCount(repeatCount) {
		}

		inline int getRepeatCount() const { return m_RepeatCount; }

		//returns wich key is pressed and how may times
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		// the getStaticType is always to get the type of the event, it can be implemented by a macro (probably in future it will)
		static	EventType	getStaticType() { return EventType::KeyPressed; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "KeyPressed"; }

	private:
		int m_RepeatCount;
	};

	class SMENG_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {
		}

		//returns wich key is released and how may times
		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;;
			return ss.str();
		}

		static	EventType	getStaticType() { return EventType::KeyReleased; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "KeyReleased"; }
	};

}
