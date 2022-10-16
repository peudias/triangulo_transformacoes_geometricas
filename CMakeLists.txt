cmake_minimum_required(VERSION 3.12)

project(compgrafica)

add_executable(compgrafica main.cpp "main.cpp")

target_include_directories(compgrafica PRIVATE 
dependencias/glm
dependencias/stb
dependencias/glfw/include
dependencias/glew/include)

target_link_directories(compgrafica PRIVATE
dependencias/glfw/lib-vc2022
dependencias/glew/lib/Release/x64)

target_link_libraries(compgrafica PRIVATE 
glfw3.lib
glew32.lib
opengl32.lib)

add_custom_command(TARGET compgrafica POST_BUILD
COMMAND ${CMAKE_COMMAND}
-E copy "${CMAKE_SOURCE_DIR}/dependencias/glew/bin/Release/x64/glew32.dll"
"${CMAKE_BINARY_DIR}")


