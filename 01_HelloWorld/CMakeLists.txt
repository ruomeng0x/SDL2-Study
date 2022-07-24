add_executable(01_HelloWorld HelloWorld.cpp)

target_link_libraries(01_HelloWorld PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static SDL2::SDL2_image)
