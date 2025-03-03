# Game Dev

## Table of Contents:
- [Introduction](#introduction)
- [Installation](#installation)
- [Features](#features)
- [Classes](#classes)


## Introduction
Game dev is a terminal strategy game made in C++ for my OOP course.
It is inspired by the acclaimed game with a similar title [Game Dev Simulator](https://store.steampowered.com/app/239820/Game_Dev_Tycoon/)


## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/TheFluffyBoi2/Game-Dev.git
   ```
2. Run CMake
   ```bash
   cmake -G "Unix Makefiles" .
   ```
3. Create the executable using Make
   ```bash
   make
   ```
4. Run the game
   ```bash
   ./GameDev
   ```

## Features
- Select from a variety of games to create:
  ```bash
  What kind of game would you like to create? :
  Horror game (1)
  Simulator (2)
  Story Game (3)
  ```
- Customise the game to your liking.
- Appease the fans and make profit:
  ```bash
  Reviews are in... :
  Future classic! 11
  Can't wait to play more games like this! 7
  Future classic! 7
  Final score: 8
  Money earned: 800$
  ```
- Earn Achievements

## Classes
- GameManager: The core of the game, GameManager is a singleton class used for the main game loop.  
