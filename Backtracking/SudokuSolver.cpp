#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    int n = board[0].size();
    for(int i = 0; i <n ; i++) {
        // Row Check
        if(board[row][i] == val) {
            return false;
        }
        // Column Check
        if(board[i][col] == val) {
            return false;
        }

        // 3*3 Matrix Check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& board) {
    int n = board[0].size();
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            // Cell Empty
            if(board[row][col] == 0) {
                for(int val = 1; val <= 9; val++) {
                    if(isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        // Recursive call
                        bool possibleSolution = solve(board);
                        if(possibleSolution) {
                            return true;
                        } else {
                            // BackTrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}