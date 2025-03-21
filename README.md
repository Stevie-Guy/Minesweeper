# Minesweeper
A simple minesweeper recreation in the console, using C++.

## Software used for this project
- Visual Studio 2022
- Compiler: gcc (MinGW.org GCC-6.3.0-1) 6.3.0

## About this project
During my first year of college, I randomly came across a programming problem with the name "Minesweeper puzzle". As I always like to try new things, the thought "Let's program Minesweeper" instantly popped up, so here it is.

## How to play the game
### 1. [Install](https://code.visualstudio.com/download) Visual Studio Code for Windows 10 and the [GCC Compiler](https://sourceforge.net/projects/mingw-w64/)(Windows 10 is necessary)
### 2. Put both files inside the same folder
### 3. Compile `Minesweeper.cpp` and then run `Minesweeper.exe` that was created in the folder


## Mechanics
- The map is randomly generated through the MapGen.hpp file;
- Enter the coordonates of the block you want to reveal and hope it is not a mine;
- If you reveal a mine ( * ) you LOSE, if you reveal a number, that number means how many mines are around that block (8 is the maximum number which can appear);
- Reveal every block which is not a mine in order to WIN.
