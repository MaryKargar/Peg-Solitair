// peg_solitaire.h

#ifndef PEG_SOLITAIRE_H
#define PEG_SOLITAIRE_H

#include <vector> // Include vector library for storing board and solution

// Structure to represent a move in the game
struct Move {
    int from_row, from_col; // Starting position of the peg
    int remove_row, remove_col; // Position of the peg being jumped over
    int to_row, to_col; // Destination position of the peg
};

// Class definition for PegSolitaire game
class PegSolitaire {
public:
    PegSolitaire(); // Constructor to initialize the game board

    bool solve(); // Function to solve the Peg Solitaire game

    // Function to get the sequence of moves in the solution
    const std::vector<Move>& get_solution() const;

private:
    // Function to check if a move is valid
    bool is_valid_move(int from_row, int from_col, int to_row, int to_col) const;

    // Function to perform a move
    void make_move(const Move& move);

    // Function to undo a move
    void undo_move(const Move& move);

    // Function to check if the game is solved (only one peg remains)
    bool is_solved() const;

    // 2D vector representing the board state
    std::vector<std::vector<char>> board;

    // Vector to store the sequence of moves that solve the game
    std::vector<Move> solution;
};

#endif // PEG_SOLITAIRE_H
