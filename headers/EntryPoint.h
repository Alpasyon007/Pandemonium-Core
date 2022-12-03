#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "Application.h"

// clang-format off
#ifdef PANDEMONIUM_PLATFORM_WINDOWS
	extern Pandemonium::Application* Pandemonium::CreateApplication();

	int main(int argc, char** argv) {
		PANDEMONIUM_PROFILE_BEGIN_SESSION("Startup", "PandemoniumProfile-Startup.json")
		Pandemonium::Application* app = Pandemonium::CreateApplication();
		PANDEMONIUM_PROFILE_END_SESSION();

		PANDEMONIUM_PROFILE_BEGIN_SESSION("Startup", "PandemoniumProfile-Runtime.json")
		app->Run();
		PANDEMONIUM_PROFILE_END_SESSION();

		PANDEMONIUM_PROFILE_BEGIN_SESSION("Startup", "PandemoniumProfile-Shutdown.json")
		delete app;
		PANDEMONIUM_PROFILE_END_SESSION();
	}
#endif
// clang-format on

#endif /* ENTRY_POINT_H */