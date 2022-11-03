#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "ApplicationEvent.h"

namespace Pandemonium {
    class PANDEMONIUM_API Application {
        public:
            Application();
            virtual ~Application();

            void Run();
    };

    Application* CreateApplication();
}

#endif /* Application_H */