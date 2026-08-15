/*
    Problem: Two Sum
    -----------------------------
    Given an array of integers nums and an integer target,
    return indices of the two numbers such that they add
    up to target. Each input has exactly one solution, and
    you may not use the same element twice.

    Example:
    Input:  nums = [2,7,11,15], target = 9
    Output: [0,1]
    (because nums[0] + nums[1] = 2 + 7 = 9)

    Input:  nums = [3,2,4], target = 6
    Output: [1,2]
*/


//But ye Approach sirf unsorted m hi use krenge agar array sorted h to two pointers approach best h 



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 19;

    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i]; // partner dhundo

        // agar partner pehle se map mein hai, to jawab mil gaya
        if (mp.find(complement) != mp.end())
        {
            cout << "[" << mp[complement] << ", " << i << "]" << endl;
            return 0;
        }

        // warna current element ko map mein daal do
        mp[nums[i]] = i;
    }

    cout << "No solution found" << endl;
    return 0;
}