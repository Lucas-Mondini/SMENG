#pragma once
#include "Core.h"


namespace SMENG {

	class SMENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		int WINDOW_W = 1280;
		int WINDOW_H = 720;
	};

	//To be defined in the client
	Application* CreateApplication();
}

