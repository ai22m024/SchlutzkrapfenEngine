#pragma once

#include "Core.h"
#include "Schlutzkrapfen/Events/Event.h"
#include "Schlutzkrapfen/Events/MouseEvents.h"
#include "Schlutzkrapfen/Events/ApplicationEvents.h"
#include "Window.h"


namespace Schlutzkrapfen {
	class SK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void Onevent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnMouseMove(MouseMovedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		float m_Mousex = 0;
		float m_Mousey = 0;
	};

		

	// Define this in client
	Application* CreateApplication();
}


