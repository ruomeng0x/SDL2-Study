# SDL2-Study

记录学习使用SDL2的过程

## 环境配置

- 操作系统：MACOS 12.5(m1)
- IDE: clion 2022.1

使用vcpkg来引入sdl2

```bash
# 安装vcpkg
mkdir ~/local
cd ~/local
git clone https://github.com/microsoft/vcpkg.git
cd ~/local/vcpkg
./bootstrap-vcpkg.sh
./vcpkg install sdl2 sdl2-image sdl2-net sdl2-ttf sdl2-mixer
 ./vcpkg integrate install
 # -DCMAKE_TOOLCHAIN_FILE=/Users/ruo/local/vcpkg/scripts/buildsystems/vcpkg.cmake
 # 将上面获得的路径作为环境变量VCPKG_CMAKE_PATH配置到~/.zshrc中
```

```text
sdl2 provides CMake targets:
# this is heuristically generated, and may not be correct
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2-static)

sdl2-image provides CMake targets:
# this is heuristically generated, and may not be correct
find_package(sdl2-image CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2_image)

sdl2-mixer provides CMake targets:
# this is heuristically generated, and may not be correct
find_package(SDL2_mixer CONFIG REQUIRED)
# note: 6 additional targets are not displayed.
target_link_libraries(main PRIVATE FLAC::FLAC MPG123::mpg123 libxmp::libxmp tremor::tremor)

sdl2-net provides CMake targets:
# this is heuristically generated, and may not be correct
find_package(sdl2-net CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2_net)

sdl2-ttf provides CMake targets:
# this is heuristically generated, and may not be correct
find_package(sdl2-ttf CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2_ttf)
```
