#include "Board.hpp"

// Constructor
Board::Board() {
    // Initialize all bitboards to zero initially
    whitePawns = 0;
    whiteKnights = 0;
    whiteBishops = 0;
    whiteRooks = 0;
    whiteQueens = 0;
    whiteKings = 0;

    blackPawns = 0;
    blackKnights = 0;
    blackBishops = 0;
    blackRooks = 0;
    blackQueens = 0;
    blackKings = 0;

    // Set up the initial position
    setupInitialPosition();
}

// Method to set up the initial chessboard position
void Board::setupInitialPosition() {
    // Set up each piece's bitboard with their initial positions
    // For example:
    whitePawns = 0x00FF000000000000; // White pawns on second rank
    whiteKnights = 0x4200000000000000; // White knights on b1 and g1
    // ...

    // Update the occupancy bitboard
    //occupancy = whitePawns | whiteKnights | /* other white pieces */ | blackPawns | /* other black pieces */;
}

// Other methods for interacting with the board can be implemented here
void Board::printBoard(){
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            uint64_t squareBit = 1ULL << square;

            // Check each piece type and print the corresponding character
            if (whitePawns & squareBit) std::cout << "P ";
            else if (whiteKnights & squareBit) std::cout << "N ";
            else if (whiteBishops & squareBit) std::cout << "B ";
            else if (whiteRooks & squareBit) std::cout << "R ";
            else if (whiteQueens & squareBit) std::cout << "Q ";
            else if (whiteKings & squareBit) std::cout << "K ";
            else if (blackPawns & squareBit) std::cout << "p ";
            else if (blackKnights & squareBit) std::cout << "n ";
            else if (blackBishops & squareBit) std::cout << "b ";
            else if (blackRooks & squareBit) std::cout << "r ";
            else if (blackQueens & squareBit) std::cout << "q ";
            else if (blackKings & squareBit) std::cout << "k ";
            else std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

void Board::makeMove(std::string move) {
    // Example move: "e2e4"
    int fromSquare = convertSquareToIndex(move.substr(0, 2));
    int toSquare = convertSquareToIndex(move.substr(2, 2));
    
    // Update piece bitboard and occupancy bitboard
    whitePawns &= ~(1ULL << fromSquare); // Clear the bit from the original square
    whitePawns |= (1ULL << toSquare);   // Set the bit in the new square
    
    // Update occupancy bitboard
    occupancy = whitePawns; // For simplicity, assuming only one piece moved
}

int convertSquareToIndex(std::string square) {
    // Extract rank and file from algebraic notation
    int rank = square[1] - '0'; // Convert character to integer (e.g., '1' -> 1)
    int file = square[0] - 'a'; // Convert character to zero-based index ('a' -> 0, 'b' -> 1, ..., 'h' -> 7)
    
    // Calculate linear index in bitboard
    int index = (rank - 1) * 8 + file;
    
    return index;
}