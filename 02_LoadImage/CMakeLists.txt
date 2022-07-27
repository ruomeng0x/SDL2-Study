add_executable(02_LoadImage LoadImage.cpp)

if (WIN32)
    target_link_libraries(02_LoadImage PRIVATE
            SDL2::SDL2
            SDL2::SDL2main
            SDL2::SDL2_image)
else ()
    target_link_libraries(02_LoadImage PRIVATE
            SDL2::SDL2
            SDL2::SDL2_image)
endif (WIN32)
