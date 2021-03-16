cmake_minimum_required(VERSION 3.12)

project(Triangulo)

add_executable(Triangulo main.cpp)

target_include_directories(Triangulo PRIVATE libs/glm
											 libs/glfw/include
											 libs/glew/include)

target_link_directories(Triangulo PRIVATE libs/glfw/lib-vc2019
										  libs/glew/lib/Release/x64)

target_link_libraries(Triangulo PRIVATE glew32.lib
									    glfw3.lib
									    opengl32.lib)

add_custom_command(TARGET Triangulo POST_BUILD COMMAND ${CMAKE_COMMAND} 
							-E copy "${CMAKE_SOURCE_DIR}/libs/glew/bin/Release/x64/glew32.dll" "${CMAKE_BINARY_DIR}/glew32.dll")