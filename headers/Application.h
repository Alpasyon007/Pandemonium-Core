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
		bool						  OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window>		  m_Window;
		ImGuiLayer*					  m_ImGuiLayer;
		bool						  m_Running = true;
		LayerStack					  m_LayerStack;

		unsigned int				  m_VertexArray;
		std::unique_ptr<Shader>		  m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer>  m_IndexBuffer;
	private:
		inline static Application* s_Instance = nullptr;
	};

	Application* CreateApplication();
} // namespace Pandemonium

#endif /* Application_H */