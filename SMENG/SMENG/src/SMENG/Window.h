#pragma once

#include "spch.h"

#include "Events/Event.h"

namespace SMENG {
	class WindowProps {
	public:
		std::string Title;
		UINT16 Width;
		UINT16 Height;

		WindowProps(const std::	string &Title = "SMENG Window", 
								UINT16 Width = 1280, 
								UINT16 Height = 720)
									: Title(Title)
									, Width(Width)
									, Height(Height){}

		};

		//This class is an interface representing a desktop system based on Windows
	class SMENG_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}


		virtual void OnUpdate() = 0;
		virtual UINT16 GetWidth() const = 0;
		virtual UINT16 GetHeight() const = 0;


		//Window attributes
		virtual bool IsVSync() = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		

		//This is basically the constructor of the class 
		static Window* Create(const WindowProps& props = WindowProps());

	};
}