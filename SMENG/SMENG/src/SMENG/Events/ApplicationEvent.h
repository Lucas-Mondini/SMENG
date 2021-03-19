#pragma once

#include "Event.h"



namespace SMENG {

	//WINDOW EVENT
	class SMENG_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width)
			, m_Height(height) {}

		inline unsigned int getWidth() const { return m_Width; }
		inline unsigned int getHeight() const { return m_Height; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: W = " << m_Width << "  H = " << m_Height;
			return ss.str();
		}

		virtual int getCategoryFlags() const override {
			return (EventCategoryApplication);
		}
		static	EventType	getStaticType() { return EventType::WindowResize; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "WindowResize"; }

	private:
		unsigned int m_Width;
		unsigned int m_Height;
	};

	class SMENG_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		virtual int getCategoryFlags() const override {
			return (EventCategoryApplication);
		}
		static	EventType	getStaticType() { return EventType::AppTick; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "AppTick"; }
	};

	class SMENG_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		virtual int getCategoryFlags() const override {
			return (EventCategoryApplication);
		}
		static	EventType	getStaticType() { return EventType::AppUpdate; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "AppUpdate"; }
	};

	class SMENG_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		virtual int getCategoryFlags() const override {
			return (EventCategoryApplication);
		}
		static	EventType	getStaticType() { return EventType::AppRender; }
		virtual EventType	getEventType()	const override { return getStaticType(); }
		virtual const char* getName()		const	 override { return "AppRender"; }
	};

}