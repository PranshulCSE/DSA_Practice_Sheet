/*
    Problem: Search a 2D Matrix
    -----------------------------
    Given an m x n matrix where each row is sorted left to
    right, and the first element of each row is greater than
    the last element of the previous row, determine if target
    exists in the matrix. Must run in O(log(m*n)).

    Example:
    Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = m * n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // 1D index ko row aur column mein convert karo
        int row = mid / n;
        int col = mid % n;

        if (matrix[row][col] == target)
        {
            cout << "true" << endl;
            return 0;
        }
        else if (matrix[row][col] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << "false" << endl;
    return 0;
}