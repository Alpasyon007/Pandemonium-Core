#ifndef LAYER_H
#define LAYER_H

#include "Core.h"
#include "Event.h"

namespace Pandemonium {

	class PANDEMONIUM_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void			  OnAttach() {}
		virtual void			  OnDetach() {}
		virtual void			  OnUpdate() {}
		virtual void			  OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
} // namespace Pandemonium

#endif /* LAYER_H */