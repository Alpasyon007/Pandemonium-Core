#include "Application.h"

namespace Pandemonium {


Application::Application() {

}

Application::~Application() {

}

void Application::Run() {
	WindowResizeEvent e(1280, 720);
	LOG_DEBUG(e.ToString().data());

	while(true) {

	}
}

}