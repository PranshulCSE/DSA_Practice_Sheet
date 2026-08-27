/*
    Problem: Search Insert Position
    -----------------------------
    Given a sorted array of distinct integers nums and a
    target value, return the index if the target is found.
    If not, return the index where it would be inserted to
    keep the array sorted. Must run in O(log n).

    Example:
    Input:  nums = [1,3,5,6], target = 5
    Output: 2

    Input:  nums = [1,3,5,6], target = 2
    Output: 1

    Input:  nums = [1,3,5,6], target = 7
    Output: 4

    Input:  nums = [1,3,5,6], target = 0
    Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 2;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            cout << mid << endl; // match mil gaya
            return 0;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // loop khatam ho gaya bina match ke -> 'left' hi insertion point hai
    cout << left << endl;
    return 0;
}