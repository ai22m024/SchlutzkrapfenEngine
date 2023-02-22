#pragma once

#include "Core.h"
namespace Schlutzkrapfen {
	class SK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// Define this in client
	Application* CreateApplication();
}


