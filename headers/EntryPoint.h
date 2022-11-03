#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "Application.h"

#ifdef PANDEMONIUM_PLATFORM_WINDOWS
    extern Pandemonium::Application* Pandemonium::CreateApplication();

    int main(int argc, char** argv) {
        Pandemonium::Application* app = Pandemonium::CreateApplication();
        app->Run();
        delete app;
    }
#endif

#endif /* ENTRY_POINT_H */