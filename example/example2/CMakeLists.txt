file(GLOB_RECURSE EXAMPLE2_SOURCE_ALL_FILES 
    "*.cpp"
    "*.h"
)

source_group("example" FILES ${EXAMPLE2_SOURCE_ALL_FILES})

add_executable(ImGuiChezzeAnimatorExampleApp2 
    ${IMGUI_FILES}
    ${CORE_SRC_FILES}
    ${EXAMPLE2_SOURCE_ALL_FILES}
)

source_group("animation" FILES ${CORE_SRC_FILES})
source_group("imgui" FILES ${IMGUI_FILES})

target_link_libraries(ImGuiChezzeAnimatorExampleApp2 PRIVATE imgui)

target_include_directories(ImGuiChezzeAnimatorExampleApp2 PUBLIC
    "${CMAKE_SOURCE_DIR}/imgui"
    "${CMAKE_SOURCE_DIR}/imgui/backends"
)