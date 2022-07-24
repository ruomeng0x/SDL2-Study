add_executable(01_HelloWorld HelloWorld.cpp)

if (WIN32)
    target_link_libraries(01_HelloWorld PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
            SDL2::SDL2_image)
else ()
    target_link_libraries(01_HelloWorld PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
            SDL2::SDL2-static
            SDL2::SDL2_image)
endif (WIN32)
