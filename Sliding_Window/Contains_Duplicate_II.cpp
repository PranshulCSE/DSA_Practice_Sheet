/*
    Problem: Contains Duplicate II
    -----------------------------
    Given an array nums and an integer k, return true if
    there are two distinct indices i and j such that
    nums[i] == nums[j] and abs(i - j) <= k.

    Example:
    Input:  nums = [1,2,3,1], k = 3
    Output: true

    Input:  nums = [1,2,3,1,2,3], k = 2
    Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    int k = 2;

    unordered_set<int> window; // sliding window of last k elements

    for (int i = 0; i < nums.size(); i++)
    {
        // agar current element window mein pehle se hai, duplicate mil gaya
        if (window.count(nums[i]))
        {
            cout << "true" << endl;
            return 0;
        }

        window.insert(nums[i]);

        // window size k se bada ho gaya, sबसे purana nikal do
        if (window.size() > k)
        {
            window.erase(nums[i - k]);
        }
    }

    cout << "false" << endl;
    return 0;
}