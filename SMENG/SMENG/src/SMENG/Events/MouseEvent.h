#pragma once

#include "Event.h"

namespace SMENG {

	//MOUSE MOVEMENT
	class SMENG_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x)
			, m_MouseY(y) {}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }


		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: X = " << m_MouseX << "  Y = " << m_MouseY;
			return ss.str();
		}

		virtual int getCategoryFlags() const override {
			return (EventCategoryMouse | EventCategoryInput);
		}
		static	EventType	getStaticType() { return EventType::MouseMoved; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "MouseMoved"; }

	private:
		float m_MouseX;
		float m_MouseY;

	};

	//MOUSE SCROLL
	class SMENG_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float x, float y)
			: m_XOffset(x)
			, m_YOffset(y){}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }


		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: X = " << m_XOffset << "  Y = " << m_YOffset;
			return ss.str();
		}


		virtual int getCategoryFlags() const override {
			return (EventCategoryMouse | EventCategoryInput);
		}
		static	EventType	getStaticType() { return EventType::MouseScrolled; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "MouseScrolled"; }

	private:
		float m_XOffset;
		float m_YOffset;
	};

	//MOUSE BUTTON CLASS (Needs to be extended)
	class SMENG_API MouseButtonEvent : public Event {
	public:
		virtual inline int getMouseButton() const { return m_Button; }

		virtual int getCategoryFlags() const override {
			return (EventCategoryMouse | EventCategoryInput);
		}

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;
	};

	//MOUSE BUTTON PRESSED CLASS (MouseButton extension)
	class SMENG_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		
		static	EventType	getStaticType() { return EventType::MouseButtonPressed; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "MouseButtonPressed"; }
	};

	//MOUSE BUTTON PRESSED CLASS (MouseButton extension)
	class SMENG_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		static	EventType	getStaticType() { return EventType::MouseButtonReleased; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "MouseButtonReleased"; }
	};



}