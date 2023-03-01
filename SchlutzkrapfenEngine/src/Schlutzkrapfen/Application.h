#pragma once

#include "Core.h"
#include "Schlutzkrapfen/Events/Event.h"
namespace Schlutzkrapfen {
	class SK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define this in client
	Application* CreateApplication();
}


