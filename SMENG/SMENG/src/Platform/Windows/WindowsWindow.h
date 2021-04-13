#pragma once

#include "SMENG/Window.h"
#include "GLFW/glfw3.h"

namespace SMENG {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline UINT16 GetWidth() const override { return w_Data.Width; }
		inline UINT16 GetHeight() const override { return w_Data.Height; }

		//Window Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { w_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;


		/*
			struct WindowData
			{
				std::string Title;
				UINT16 Width, Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};
		*/

		
		struct WindowData : public WindowProps
		{
			bool VSync;

			EventCallbackFn EventCallback;
		};
		
		WindowData w_Data;


	};
}


