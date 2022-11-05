#include "Application.h"

namespace Pandemonium {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }

	void Application::PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); }

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		LOG_INFO(e.ToString());

		for(std::vector<Layer*>::iterator it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if(e.Handled) { break; }
		}
	}

	void Application::Run() {
		// WindowResizeEvent e(1280, 720);
		// LOG_DEBUG(e.ToString().data());

		while(m_Running) {
			for(Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
} // namespace Pandemonium