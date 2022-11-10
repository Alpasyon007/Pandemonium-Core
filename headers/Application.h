#ifndef APPLICATION_H
#define APPLICATION_H

#include "ApplicationEvent.h"
#include "Core.h"
#include "Event.h"
#include "LayerStack.h"
#include "Window.h"

#include "ImGuiLayer.h"

#include "Buffer.h"
#include "Shader.h"
#include "VertexArray.h"

namespace Pandemonium {
	class PANDEMONIUM_API Application {
	public:
		Application();
		virtual ~Application();

		void					   Run();

		void					   OnEvent(Event& e);

		void					   PushLayer(Layer* layer);
		void					   PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }

		inline Window&			   GetWindow() { return *m_Window; }
	private:
		bool						 OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window>		 m_Window;
		ImGuiLayer*					 m_ImGuiLayer;
		bool						 m_Running = true;
		LayerStack					 m_LayerStack;

		std::shared_ptr<Shader>		 m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<VertexArray> m_SquareVA;
		std::shared_ptr<Shader>		 blueShader;
	private:
		inline static Application* s_Instance = nullptr;
	};

	Application* CreateApplication();
} // namespace Pandemonium

#endif /* Application_H */