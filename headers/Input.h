#ifndef INPUT_H
#define INPUT_H

#include "Core.h"

namespace Pandemonium {

	class PANDEMONIUM_API Input {
	public:
		inline static bool					  IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool					  IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }

		inline static float					  GetMouseX() { return s_Instance->GetMosueXImpl(); }

		inline static float					  GetMouseY() { return s_Instance->GetMosueYImpl(); }

		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }
	protected:
		virtual bool					IsKeyPressedImpl(int keycode)		 = 0;

		virtual bool					IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePosImpl()					 = 0;
		virtual float					GetMosueXImpl()						 = 0;
		virtual float					GetMosueYImpl()						 = 0;
	private:
		static Input* s_Instance;
	};

} // namespace Pandemonium

#endif /* INPUT_H */