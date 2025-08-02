file(GLOB_RECURSE EXAMPLE1_SOURCE_ALL_FILES 
    "*.cpp"
    "*.h"
)

source_group("example" FILES ${EXAMPLE1_SOURCE_ALL_FILES})

add_executable(ImGuiChezzeAnimatorExampleApp1
    ${IMGUI_FILES}
    ${CORE_SRC_FILES}
    ${EXAMPLE1_SOURCE_ALL_FILES}
)

source_group("animation" FILES ${CORE_SRC_FILES})
source_group("imgui" FILES ${IMGUI_FILES})

target_link_libraries(ImGuiChezzeAnimatorExampleApp1 PRIVATE imgui)

target_include_directories(ImGuiChezzeAnimatorExampleApp1 PUBLIC
    "${CMAKE_SOURCE_DIR}/imgui"
    "${CMAKE_SOURCE_DIR}/imgui/backends"
)
