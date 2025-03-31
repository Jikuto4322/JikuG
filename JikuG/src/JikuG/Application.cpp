#include "Application.h"
#include "JikuG/Events/ApplicationEvent.h"
#include "JikuG/Log.h"

namespace JikuG {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		JG_TRACE(e);

		while (true);
	}
}
