#pragma once

#ifdef SK_PLATFORM_WINDOWS

extern Schlutzkrapfen::Application* Schlutzkrapfen::CreateApplication();

int main(int argc, char** argv) {
	Schlutzkrapfen::Log::Init();
	SK_CORE_WARN("Init Logging!");
	int a = 12345;
	SK_INFO("Hello! {0}", a);

	auto app = Schlutzkrapfen::CreateApplication();
	app->run();
	delete app;
}

#endif