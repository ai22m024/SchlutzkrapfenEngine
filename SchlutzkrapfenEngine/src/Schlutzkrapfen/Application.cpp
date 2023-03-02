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
		dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(OnMouseMove));

		SK_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		
		// Test Logging System with Events
		if (e.IsInCategory(EventCategoryApplication)) {
			SK_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			SK_INFO(e);
		}

		int width = m_Window->GetWidth();
		int height = m_Window->GetHeight();

		while (m_Running) {
			
			float valx = m_Mousex / float(width);
			float valy = m_Mousey / float(height);

			glClearColor(valx, valy, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}


	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		m_Running = false;
		return true;
	}

	bool Application::OnMouseMove(MouseMovedEvent& e)
	{
		m_Mousex = e.GetX();
		m_Mousey = e.GetY();
		return true;
	}
}

