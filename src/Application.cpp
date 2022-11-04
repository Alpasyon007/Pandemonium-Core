#include "Application.h"

namespace Pandemonium {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application() {}

	void Application::OnEvent(Event& e) {
		LOG_INFO(e.ToString().data());
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
	}

	void Application::Run() {
		// WindowResizeEvent e(1280, 720);
		// LOG_DEBUG(e.ToString().data());

		while(m_Running) {
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
} // namespace Pandemonium