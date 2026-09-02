/*
    Problem: Find Peak Element
    -----------------------------
    A peak element is an element strictly greater than its
    neighbors. Given an array nums, find any peak element's
    index. Assume nums[-1] = nums[n] = -infinity. Must run
    in O(log n).

    Example:
    Input:  nums = [1,2,3,1]
    Output: 2
    (index 2 has value 3, greater than neighbors 2 and 1)

    Input:  nums = [1,2,1,3,5,6,4]
    Output: 1 or 5
    (both are valid peaks)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            // hum chadh rahe hain, peak right side mein hai
            left = mid + 1;
        }
        else
        {
            // hum utar rahe hain (ya mid hi peak hai), peak yahan ya left mein hai
            right = mid;
        }
    }

    // left == right, yahi peak hai
    cout << left << endl;
    return 0;
}
