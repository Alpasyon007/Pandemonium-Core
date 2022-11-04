#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "Application.h"

// clang-format off
#ifdef PANDEMONIUM_PLATFORM_WINDOWS
	extern Pandemonium::Application* Pandemonium::CreateApplication();

	int main(int argc, char** argv) {
		Pandemonium::Application* app = Pandemonium::CreateApplication();
		app->Run();
		delete app;
	}
#endif
// clang-format on

#endif /* ENTRY_POINT_H */