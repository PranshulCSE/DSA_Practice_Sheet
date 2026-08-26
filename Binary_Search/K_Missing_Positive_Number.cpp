/*
    Problem: Kth Missing Positive Number
    -----------------------------
    Given a sorted, strictly increasing array of positive
    integers arr and an integer k, return the kth positive
    integer that is missing from this array.

    Example:
    Input:  arr = [2,3,4,7,11], k = 5
    Output: 9
    (missing sequence: 1,5,6,8,9,... -> 5th missing = 9)

    Input:  arr = [1,2,3,4], k = 2
    Output: 6
    (missing sequence: 5,6,7,... -> 2nd missing = 6)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // is index tak kitne numbers missing hain
        int missingCount = arr[mid] - (mid + 1);

        if (missingCount < k)
        {
            // abhi kaafi missing nahi mile, aage badho
            left = mid + 1;
        }
        else
        {
            // ye ya isse pehle answer ho sakta hai
            right = mid - 1;
        }
    }

    // left position tak 'left' elements the jo non-missing the array mein
    // answer = left + k
    int result = left + k;

    cout << result << endl;
    return 0;
}