// peg_solitaire.cpp

#include "peg_solitaire.h" // Include the header file for PegSolitaire class
#include <iostream> // Include the input-output stream library

// Constructor to initialize the board with the starting state
PegSolitaire::PegSolitaire() {
    board = {
        {'-', '-', 'o', 'o', 'o', '-', '-'}, // Top row with empty spaces and pegs
        {'-', '-', 'o', 'o', 'o', '-', '-'},
        {'o', 'o', 'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', '.', 'o', 'o', 'o'}, // Middle row with an empty space in the center
        {'o', 'o', 'o', 'o', 'o', 'o', 'o'},
        {'-', '-', 'o', 'o', 'o', '-', '-'},
        {'-', '-', 'o', 'o', 'o', '-', '-'}  // Bottom row with empty spaces and pegs
    };
}

// Function to check if a move is valid
bool PegSolitaire::is_valid_move(int from_row, int from_col, int to_row, int to_col) const {
    // Check if the move is within bounds
    if (from_row < 0 || from_row >= 7 || from_col < 0 || from_col >= 7 ||
        to_row < 0 || to_row >= 7 || to_col < 0 || to_col >= 7) {
        return false; // Return false if the move is out of bounds
    }

    // Check if the starting position has a peg and the destination is empty
    if (board[from_row][from_col] != 'o' || board[to_row][to_col] != '.') {
        return false; // Return false if no peg to move or destination is not empty
    }

    // Calculate the coordinates of the middle cell being jumped over
    int mid_row = (from_row + to_row) / 2;
    int mid_col = (from_col + to_col) / 2;

    // Check if the middle cell contains a peg
    if (board[mid_row][mid_col] != 'o') {
        return false; // Return false if there's no peg to jump over
    }

    // Valid if jumping over a peg either vertically or horizontally
    return (abs(from_row - to_row) == 2 && from_col == to_col) ||  // Vertical move
           (abs(from_col - to_col) == 2 && from_row == to_row);    // Horizontal move
}

// Function to make a move
void PegSolitaire::make_move(const Move& move) {
    // Perform the move: remove the peg from the starting position
    board[move.from_row][move.from_col] = '.';
    // Remove the peg that is jumped over
    board[move.remove_row][move.remove_col] = '.';
    // Place a peg at the destination position
    board[move.to_row][move.to_col] = 'o';

    // Add the move to the solution sequence
    solution.push_back(move);
}

// Function to undo a move
void PegSolitaire::undo_move(const Move& move) {
    // Reverse the move: place the peg back at the starting position
    board[move.from_row][move.from_col] = 'o';
    // Place the peg back in the middle position
    board[move.remove_row][move.remove_col] = 'o';
    // Remove the peg from the destination position
    board[move.to_row][move.to_col] = '.';

    // Remove the move from the solution sequence
    solution.pop_back();
}

// Function to check if the game is solved (only one peg remains)
bool PegSolitaire::is_solved() const {
    int peg_count = 0; // Initialize peg counter
    for (const auto& row : board) { // Iterate through each row
        for (char cell : row) { // Iterate through each cell in the row
            if (cell == 'o') { // If the cell contains a peg
                peg_count++; // Increment peg count
            }
        }
    }
    return peg_count == 1; // Return true if only one peg remains
}

// Recursive function to solve the game
bool PegSolitaire::solve() {
    if (is_solved()) { // Check if the game is already solved
        return true; // Return true if solved
    }

    // Iterate through all possible moves on the board
    for (int from_row = 0; from_row < 7; ++from_row) {
        for (int from_col = 0; from_col < 7; ++from_col) {
            for (int d_row = -2; d_row <= 2; ++d_row) {
                for (int d_col = -2; d_col <= 2; ++d_col) {
                    int to_row = from_row + d_row;
                    int to_col = from_col + d_col;
                    // Check if the current move is valid
                    if (is_valid_move(from_row, from_col, to_row, to_col)) {
                        // Create a move structure for this valid move
                        Move move = {from_row, from_col, (from_row + to_row) / 2, (from_col + to_col) / 2, to_row, to_col};
                        make_move(move); // Perform the move
                        if (solve()) { // Recursively attempt to solve the board
                            return true; // Return true if solved
                        }
                        undo_move(move); // Undo the move if it didn't lead to a solution
                    }
                }
            }
        }
    }
    return false; // Return false if no solution is found
}

// Function to get the solution sequence
const std::vector<Move>& PegSolitaire::get_solution() const {
    return solution; // Return the sequence of moves in the solution
}
