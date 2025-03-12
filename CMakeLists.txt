cmake_minimum_required(VERSION 3.27)
project(GameDev)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(GameDev
        main.cpp
        headers/gameCreator.h
        src/gameCreator.cpp
        headers/horrorGame.h
        src/horrorGame.cpp
        headers/storyGame.h
        src/storyGame.cpp
        headers/Simulator.h
        src/Simulator.cpp
        headers/Achievements.h
        src/Achievements.cpp
        headers/Game.h
        src/Game.cpp
        headers/gameManager.h
        src/gameManager.cpp
        headers/Player.h
        src/Player.cpp
        headers/Profit.h
)