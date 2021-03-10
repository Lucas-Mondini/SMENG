#include "Application.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "SMENG/Log.h"


namespace SMENG{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(WINDOW_W, WINDOW_H);
		SMENG_CLIENT_TRACE(e);

		while (true);
	}
}