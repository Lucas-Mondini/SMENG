#pragma once
#include "Core.h"
#include "Window.h"

namespace SMENG {

	class SMENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool Running = true;
	};

	//To be defined in the client
	Application* CreateApplication();
}

