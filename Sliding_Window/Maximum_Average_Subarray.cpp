/*
    Problem: Maximum Average Subarray I
    -----------------------------
    Given an array nums and an integer k, find the contiguous
    subarray of length k that has the maximum average value,
    and return that average.

    Example:
    Input:  nums = [1,12,-5,-6,50,3], k = 4
    Output: 12.75000
    (subarray [12,-5,-6,50] has sum 51, avg 51/4 = 12.75)

    Input:  nums = [5], k = 1
    Output: 5.00000
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // pehle k elements ka sum nikal lo
    long long windowSum = 0;
    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }

    long long maxSum = windowSum;

    // ab window ko slide karte jao
    for (int i = k; i < nums.size(); i++)
    {
        windowSum += nums[i] - nums[i - k]; // naya add, purana minus
        maxSum = max(maxSum, windowSum);
    }

    double result = (double)maxSum / k;
    cout << result << endl;

    return 0;
}