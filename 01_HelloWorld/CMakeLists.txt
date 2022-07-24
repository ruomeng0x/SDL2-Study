add_executable(01_HelloWorld HelloWorld.cpp)

if (WIN32)
    target_link_libraries(01_HelloWorld PRIVATE
            SDL2::SDL2
            SDL2::SDL2main)
else ()
    target_link_libraries(01_HelloWorld PRIVATE
            SDL2::SDL2)
endif (WIN32)
