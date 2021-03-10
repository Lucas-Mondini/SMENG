#pragma once

#include "SMENG/Core.h"

#include <string>
#include <functional>

namespace SMENG {


	enum class EventType {
		None = 0,

		//Window
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		//App
		AppTick,
		AppUpdate,
		AppRender,

		//Key
		KeyPressed,
		KeyReleased,

		//Mouse
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= LShiftbit(0),
		EventCategoryInput			= LShiftbit(1),
		EventCategoryKeyboard		= LShiftbit(2),
		EventCategoryMouse			= LShiftbit(3),
		EventCategoryMouseButton	= LShiftbit(4),

	};


	class SMENG_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType getEventType()	const = 0;
		virtual const char* getName()		const = 0;
		virtual int getCategoryFlags()		const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;

	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event){
		}
		//Dispatch() will return true if the template is the same time of the function that is trying to call
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.getEventType() == T::getStaticType()) {
				m_Event.m_Handled = func(*(T*) &m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
	
}