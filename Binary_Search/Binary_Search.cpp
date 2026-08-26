/*
    Problem: Binary Search
    -----------------------------
    Given a sorted (ascending) array of unique integers nums
    and a target value, return the index of target if it
    exists in nums, otherwise return -1. Must run in O(log n).

    Example:
    Input:  nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    (9 is at index 4)

    Input:  nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    (2 is not in nums)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // overflow-safe mid calculation

        if (nums[mid] == target)
        {
            cout << mid << endl; // mil gaya!
            return 0;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // target right side mein hai
        }
        else
        {
            right = mid - 1; // target left side mein hai
        }
    }

    cout << -1 << endl; // nahi mila
    return 0;
}