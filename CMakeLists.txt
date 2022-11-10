file(
	GLOB_RECURSE
	HEADERS
	CONFIGURE_DEPENDS
	"*.h"
)

file(
	GLOB_RECURSE
	SRC
	CONFIGURE_DEPENDS
	"*.cpp"
)

target_sources(PandemoniumCore PUBLIC ${HEADERS} ${SRC})

# target_sources( PandemoniumCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include/PandemoniumCore.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Window.h
# ${CMAKE_CURRENT_SOURCE_DIR}/headers/EntryPoint.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Core.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Application.h
# ${CMAKE_CURRENT_SOURCE_DIR}/headers/Layer.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/LayerStack.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/Input.h
# ${CMAKE_CURRENT_SOURCE_DIR}/headers/KeyCodes.h ${CMAKE_CURRENT_SOURCE_DIR}/headers/MouseButtonCodes.h ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
# ${CMAKE_CURRENT_SOURCE_DIR}/src/Core.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Layer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/LayerStack.cpp )

target_include_directories(
	PandemoniumCore
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/headers
			${CMAKE_CURRENT_SOURCE_DIR}/src
			${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-ImGui/headers
			${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Log/Include
			${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glfw/Include
			${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/glad/Include
			${CMAKE_CURRENT_SOURCE_DIR}/../Pandemonium-Renderer/headers
)
