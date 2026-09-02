
/*
    Problem: Find First and Last Position of Element in Sorted Array
    -----------------------------
    Given a sorted array nums (may contain duplicates) and a
    target, return [first, last] indices of target. If not
    found, return [-1,-1]. Must run in O(log n).

    Example:
    Input:  nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Input:  nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
*/

#include <iostream>
#include <vector>
using namespace std;

// pehla occurrence dhundo
int findFirst(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            result = mid;    // ye ek valid answer hai
            right = mid - 1; // lekin aur pehle bhi ho sakta hai, left mein dhundo
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
    return result;
}

// aakhri occurrence dhundo
int findLast(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            result = mid;   // ye ek valid answer hai
            left = mid + 1; // lekin aur aage bhi ho sakta hai, right mein dhundo
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
    return result;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    cout << "[" << first << ", " << last << "]" << endl;

    return 0;
}