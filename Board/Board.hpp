#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>
#include <iostream>

class Board {
private:
    // Define the types of pieces as bitboards
    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKings;

    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKings;

    // Define the occupancy bitboard
    uint64_t occupancy;

public:
    // Constructor
    Board();

    // Method to set up the initial chessboard position
    void setupInitialPosition();

    // Other methods for interacting with the board, e.g., movePiece, printBoard, etc.
    void printBoard();

    void makeMove(std::string);

    int convertSquareToIndex(std::string);
};


#endif // BOARD_HPP