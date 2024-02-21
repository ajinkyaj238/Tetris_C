cmake_minimum_required(VERSION 3.0.0)
project(sdl2_game VERSION 0.1.0 LANGUAGES C CXX)


add_executable(sdl2_game tetris.cpp)

#linux
target_link_libraries(sdl2_game SDL2main SDL2 X11)

#windows
#target_link_libraries(sdl2_game SDL2main SDL2)

#macos
#target_link_libraries(sdl2_game SDL2main SDL2 -framework SDL2 -framework Cocoa -framework CoreGraphics)

