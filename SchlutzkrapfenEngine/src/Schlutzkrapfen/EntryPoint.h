#pragma once

#ifdef SK_PLATFORM_WINDOWS

extern Schlutzkrapfen::Application* Schlutzkrapfen::CreateApplication();

int main(int argc, char** argv) {
	auto app = Schlutzkrapfen::CreateApplication();
	app->run();
	delete app;
}

#endif