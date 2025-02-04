Peg Solitaire Solver
====================


This project is a C++ program that solves the Peg Solitaire game. It finds a solution and shows the moves needed to solve it. The game starts with the board set up like this:

  [[-,-,o,o,o,-,-],
   [-,-,o,o,o,-,-],
   [o,o,o,o,o,o,o],
   [o,o,o,.,o,o,o],
   [o,o,o,o,o,o,o],
   [-,-,o,o,o,-,-],
   [-,-,o,o,o,-,-]]

The moves are shown as a list like this:

[[[2,4],[3,4],[4,4]], [[3,2],[3,3],[3,4]], ...]

Each move is given as [From, Removed, To], where the coordinates start at 1.

How to Build the Project

To build the project, you need to use CMake and a C++ compiler. Here are the steps:

Make sure you have CMake installed on your computer.

Open a terminal and go to the project folder.

Run the following commands:

mkdir build
cd build
cmake ..
make

This will create an executable file in the build/bin folder.

How to Run the Program

After building, you can run the program by using this command:

./bin/peg_solitaire

The program will solve the game and print the list of moves needed to complete it.

Requirements

CMake (version 3.29 or higher)

A C++ compiler that supports C++17

Files Included

main.cpp: The main file to run the program.

peg_solitaire.cpp: The implementation of the Peg Solitaire game logic.

peg_solitaire.h: The header file for the Peg Solitaire class.

CMakeLists.txt: The CMake file to build the project.

Notes

The output uses coordinates starting at 1, as requested.

The program is optimized for release mode, so it runs faster when built with optimizations.