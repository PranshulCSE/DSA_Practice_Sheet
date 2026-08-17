/*
    Problem: Remove Duplicates from Sorted Array
    -----------------------------
    Given a sorted array nums, remove duplicates in-place
    such that each unique element appears only once. Return
    the number of unique elements k. The first k elements of
    nums should hold the final result in order.

    Example:
    Input:  nums = [1,1,2]
    Output: k = 2, nums = [1,2,_]

    Input:  nums = [0,0,1,1,1,2,2,3,3,4]
    Output: k = 5, nums = [0,1,2,3,4,_,_,_,_,_]
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    if (nums.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int i = 0; // slow pointer -> last unique element ka index

    for (int j = 1; j < nums.size(); j++)
    {
        // agar naya element mila (pichle unique se different)
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j]; // unique position pe likh do
        }
    }

    int k = i + 1; // total unique elements

    cout << "k = " << k << ", nums = [ ";
    for (int idx = 0; idx < k; idx++)
    {
        cout << nums[idx] << " ";
    }
    cout << "]" << endl;

    return 0;
}