#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationEvent.h"
#include "Core.h"
#include "Event.h"
#include "Window.h"

namespace Pandemonium {
	class PANDEMONIUM_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool					OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool					m_Running = true;
	};

	Application* CreateApplication();
} // namespace Pandemonium

#endif /* Application_H */