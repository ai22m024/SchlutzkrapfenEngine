#include "skpch.h"

#include "Application.h"
#include "Schlutzkrapfen/Events/ApplicationEvents.h"
#include "Schlutzkrapfen/Log.h"

#include "GLFW/glfw3.h"

namespace Schlutzkrapfen {
	Schlutzkrapfen::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
		while (m_running) {
			float val = (float)((int)(glfwGetTime()*30) % 255) / 255.0f;

			glClearColor(1-val, val, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}

