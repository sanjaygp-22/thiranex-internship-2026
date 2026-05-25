#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << "\n";

        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check winner
bool checkWinner(char board[3][3], char player) {

    // Check rows and columns
    for (int i = 0; i < 3; i++) {

        // Rows
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        // Columns
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Function to check draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {

    char playAgain;

    do {

        // Initialize board
        char board[3][3] = {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
        };

        int choice;
        int row, col;
        char currentPlayer = 'X';

        bool gameOver = false;

        cout << "===== TIC TAC TOE =====\n";

        while (!gameOver) {

            displayBoard(board);

            cout << "Player " << currentPlayer
                 << ", enter a number (1-9): ";
            cin >> choice;

            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            // Check valid move
            if (board[row][col] != 'X' &&
                board[row][col] != 'O') {

                board[row][col] = currentPlayer;

                // Check winner
                if (checkWinner(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player "
                         << currentPlayer
                         << " wins!\n";
                    gameOver = true;
                }

                // Check draw
                else if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "Game is a draw!\n";
                    gameOver = true;
                }

                // Switch player
                else {
                    if (currentPlayer == 'X')
                        currentPlayer = 'O';
                    else
                        currentPlayer = 'X';
                }

            } else {
                cout << "Invalid move! Try again.\n";
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
