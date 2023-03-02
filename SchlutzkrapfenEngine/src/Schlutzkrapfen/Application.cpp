#include "skpch.h"

#include "Application.h"
#include "Schlutzkrapfen/Log.h"

#include "GLFW/glfw3.h"

namespace Schlutzkrapfen {

#define BIND_EVENT_FN(x) std::bind(&Application::x,this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::Onevent));
	}

	Application::~Application()
	{
	}
	void Application::Onevent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SK_CORE_TRACE("{0}", e);
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
		while (m_Running) {
			float val = (float)((int)(glfwGetTime()*30) % 255) / 255.0f;

			glClearColor(1-val, val, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}


	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		m_Running = false;
		return true;
	}
}

