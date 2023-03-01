#include "Application.h"
#include "Schlutzkrapfen/Events/ApplicationEvents.h"
#include "Schlutzkrapfen/Log.h"

namespace Schlutzkrapfen {
	Schlutzkrapfen::Application::Application()
	{
	}

	Schlutzkrapfen::Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);

		if (e.IsInCategory(EventCategoryApplication)) {
			SK_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			SK_INFO(e);
		}
		while (true);
	}
}

