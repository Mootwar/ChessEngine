/*
    Chess Engine Project
*/
#include <iostream>
#include "Board/Board.hpp"
#include <cstdint>

// Function to finish the game based on the game over condition
void finishGame(bool gameOver) {
    if (gameOver) {
        std::cout << "Game Over!" << std::endl;
        // Additional logic for game over actions, such as printing the winner
    }
}

int main() {
    // Set up the initial position
    bool gameOver = false;
    // Main game loop and other logic
    // ...
    std::cout << "Welcome to MyChessEngine!" << std::endl;

    // Initialize board, engine, etc.
    Board chessBoard;
    std::cout << chessBoard.convertSquareToIndex("h8");
    chessBoard.printBoard();
    // Main loop for the game
    // The game starts
    while (!gameOver) {
        // userIn =
        // User makes a move
        // chessBoard.makeMove();
        // Print board state
        chessBoard.printBoard();
        char n;
        std::cin >> n;
        // Check for end conditions (checkmate, stalemate, etc.)
        // gameOver = chessBoard.criticalCheck();
        // Finish the game if the game is over
        finishGame(gameOver);
        
        // Bot makes a move
        // chessBoard.botMove();
        // Print board state
        // chessBoard.printBoard();
        // Check for end conditions
        // gameOver = chessBoard.criticalCheck();
        // Finish the game if the game is over
        finishGame(gameOver);
    }

    return 0;
}