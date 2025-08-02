cmake_minimum_required(VERSION 3.15)


project(ImGuiAnimations)

#set(CMAKE_CXX_STANDARD 17)

file(GLOB CORE_SRC_FILES 
	"${CMAKE_SOURCE_DIR}/*.cpp" 
	"${CMAKE_SOURCE_DIR}/*.h"
)

file(GLOB IMGUI_CORE_FILES
	"${CMAKE_SOURCE_DIR}/imgui/*.cpp" 
	"${CMAKE_SOURCE_DIR}/imgui/*.h"
)

file(GLOB IMGUI_FILES
	"${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_win32.*"
	"${CMAKE_SOURCE_DIR}/imgui/backends/imgui_impl_dx9.*"
)

set(IMGUI_ALL_FILES ${IMGUI_FILES} ${IMGUI_CORE_FILES})

add_library(imgui STATIC
    ${IMGUI_CORE_FILES}
    ${IMGUI_BACKEND_FILES}
)

add_subdirectory("example/example1")
add_subdirectory("example/example2")

