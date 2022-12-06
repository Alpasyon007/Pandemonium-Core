#include "ppch.h"

#include "Application.h"
#include "Input.h"

#include "Renderer.h"

#include "glfw/glfw3.h"

namespace Pandemonium {

	Application::Application() {
		PANDEMONIUM_PROFILE_FUNCTION();

		ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window   = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() { PANDEMONIUM_PROFILE_FUNCTION(); }

	void Application::PushLayer(Layer* layer) {
		PANDEMONIUM_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		PANDEMONIUM_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		PANDEMONIUM_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&Application::OnWindowResize, this, std::placeholders::_1));

		for(std::vector<Layer*>::iterator it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if(e.Handled) { break; }
		}
	}

	void Application::Run() {
		PANDEMONIUM_PROFILE_FUNCTION();

		while(m_Running) {
			PANDEMONIUM_PROFILE_SCOPE("RunLoop");

			float	 time	  = static_cast<float>(glfwGetTime()); // Should be Platform::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime	  = time;

			if(!m_Minimized) {
				{
					PANDEMONIUM_PROFILE_SCOPE("LayerStack OnUpdate");

					for(Layer* layer : m_LayerStack) {
						layer->OnUpdate(timestep);
					}
				}

				m_ImGuiLayer->Begin();
				{
					PANDEMONIUM_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for(Layer* layer : m_LayerStack) {
						layer->OnImGuiRender();
					}
				}
				m_ImGuiLayer->End();
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		PANDEMONIUM_PROFILE_FUNCTION();

		if(e.GetWidth() == 0 || e.GetHeight() == 0) {
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return false;
	}

} // namespace Pandemonium