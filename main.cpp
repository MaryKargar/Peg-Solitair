// main.cpp

#include <iostream> // Include the input-output stream library
#include "peg_solitaire.h" // Include the header file for PegSolitaire game logic

int main() {
    PegSolitaire game; // Create an instance of the PegSolitaire game

    if (game.solve()) { // Attempt to solve the game and check if a solution is found
        std::cout << "Solution found!\n"; // Print message indicating that a solution was found

        const auto& solution = game.get_solution(); // Get the solution moves sequence
        for (const auto& move : solution) { // Loop through each move in the solution
            std::cout << "[[" << move.from_row + 1 << "," << move.from_col + 1 << "],"
                      << "[" << move.remove_row + 1 << "," << move.remove_col + 1 << "],"
                      << "[" << move.to_row + 1 << "," << move.to_col + 1 << "]]\n";
            // Print each move in the format: [[from_row, from_col], [remove_row, remove_col], [to_row, to_col]]
            // Adding 1 to each row and column to convert from zero-based to one-based indexing
        }
    } else {
        std::cout << "No solution found.\n"; // Print message if no solution is found
    }

    return 0; // Indicate successful program termination
}
