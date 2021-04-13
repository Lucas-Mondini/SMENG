#include "spch.h"
#include "WindowsWindow.h"
#include <SMENG/Log.h>


namespace SMENG {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		w_Data.Title = props.Title;
		w_Data.Width = props.Width;
		w_Data.Height = props.Height;
		
		SMENG_CORE_INFO("Creating a window {0} ({1} X {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			
			SMG_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)w_Data.Width,
									(int)w_Data.Height,
									w_Data.Title.c_str(),
									nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &w_Data);
		SetVSync(true);
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		glfwSwapInterval(enabled);
		w_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync()
	{
		const bool b = w_Data.VSync;
		return b;
	}

	
}