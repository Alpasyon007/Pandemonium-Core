#include "Application.h"
#include "Input.h"

#include "Renderer.h"

#include "glfw/glfw3.h"

namespace Pandemonium {

	Application::Application() {
		ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window   = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for(std::vector<Layer*>::iterator it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if(e.Handled) { break; }
		}
	}

	void Application::Run() {
		while(m_Running) {
			float	 time	  = (float)glfwGetTime(); // Should be Platform::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime	  = time;

			for(Layer* layer : m_LayerStack) {
				layer->OnUpdate(timestep);
			}

			m_ImGuiLayer->Begin();
			for(Layer* layer : m_LayerStack) {
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

} // namespace Pandemonium