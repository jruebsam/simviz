cmake_minimum_required(VERSION 3.18.4)
project(simcanvas LANGUAGES CUDA CXX)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(
    sim 
    src/main.cpp
    src/glad.cpp
    src/Window.cpp
)

target_include_directories(sim PUBLIC include)
target_link_libraries(sim ${CONAN_LIBS})


add_custom_command(
    TARGET sim POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink              
        ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:sim>/shaders
    COMMENT "Creating symlink to shader directory" VERBATIM
)
