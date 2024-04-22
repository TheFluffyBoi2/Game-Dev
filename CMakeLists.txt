cmake_minimum_required(VERSION 3.27)
project(GameDev)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameDev main.cpp
        Game.cpp
        Game.h
        horrorGame.cpp
        horrorGame.h
        Simulator.cpp
        Simulator.h
        Player.cpp
        Player.h
        storyGame.cpp
        storyGame.h
        gameManager.cpp
        gameManager.h)
