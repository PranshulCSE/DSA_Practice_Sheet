/*
    Problem: Valid Sudoku
    -----------------------------
    Determine if a 9x9 Sudoku board is valid. Only the
    filled cells need to be validated according to these
    rules:
    1. Each row must contain digits 1-9 without repetition.
    2. Each column must contain digits 1-9 without repetition.
    3. Each of the nine 3x3 sub-boxes must contain digits
       1-9 without repetition.
    Empty cells are denoted by '.'

    Example:
    Input: board (partially filled 9x9 grid with '.' for empty)
    Output: true  (no row/col/box has repeating digit)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    unordered_set<int> rows[9], cols[9], boxes[9]; // 9-9 sets teeno ke liye

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            char ch = board[r][c];
            if (ch == '.')
                continue; // empty cell, skip karo

            int digit = ch - '0';
            int boxIndex = (r / 3) * 3 + (c / 3); // kaunsa 3x3 box hai

            // agar digit teeno mein se kahin bhi already hai -> invalid
            if (rows[r].count(digit) || cols[c].count(digit) || boxes[boxIndex].count(digit))
            {
                cout << "false" << endl;
                return 0;
            }

            // warna teeno sets mein insert kar do
            rows[r].insert(digit);
            cols[c].insert(digit);
            boxes[boxIndex].insert(digit);
        }
    }

    cout << "true" << endl;
    return 0;
}