#include "ppch.h"
#include "LayerStack.h"

namespace Pandemonium {

	LayerStack::LayerStack() {}

	LayerStack::~LayerStack() {
		for(Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay) { m_Layers.emplace_back(overlay); }

	void LayerStack::PopLayer(Layer* layer) {
		std::vector<Layer*>::iterator layerBegin = m_Layers.begin();
		std::vector<Layer*>::iterator it		 = std::find(layerBegin, m_Layers.end(), layer);
		if(it != layerBegin) {
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		std::vector<Layer*>::iterator it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if(it != m_Layers.end()) { m_Layers.erase(it); }
	}

} // namespace Pandemonium