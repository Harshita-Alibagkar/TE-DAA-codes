#include<iostream>

using namespace std;

const int MAX_N = 10; // Maximum value of N

// Function to print the chessboard
void printBoard(int board[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[MAX_N][MAX_N], int col, int N) {
    if (col == N) {
        // All queens are placed successfully
        // Print the solution
        printBoard(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place the queen at board[i][col]
            board[i][col] = 1;

            // Recur for the next column
            res = solveNQueens(board, col + 1, N) || res;

            // Backtrack and remove the queen from board[i][col]
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int board[MAX_N][MAX_N] = {0}; // Initialize the chessboard

    if (solveNQueens(board, 0, N) == false) {
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}
