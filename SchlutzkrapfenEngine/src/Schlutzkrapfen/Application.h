#pragma once

#include "Core.h"
#include "Schlutzkrapfen/Events/Event.h"
#include "Window.h"


namespace Schlutzkrapfen {
	class SK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
	};

		

	// Define this in client
	Application* CreateApplication();
}


