cmake_minimum_required(VERSION 3.15)


project(ChezzeAnimator)

#set(CMAKE_CXX_STANDARD 17)

file(GLOB CORE_SRC_FILES 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" 
	"${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")

file(GLOB IMGUI_CORE_FILES
	"${IMGUI_DIR}/*.cpp" 
	"${IMGUI_DIR}/imgui/*.h"
)

file(GLOB IMGUI_FILES
	"${IMGUI_DIR}/backends/imgui_impl_win32.*"
	"${IMGUI_DIR}/backends/imgui_impl_dx9.*"
)

set(IMGUI_ALL_FILES ${IMGUI_FILES} ${IMGUI_CORE_FILES})

add_library(imgui STATIC
    ${IMGUI_CORE_FILES}
    ${IMGUI_BACKEND_FILES}
)

add_subdirectory("example/example1")
add_subdirectory("example/example2")

