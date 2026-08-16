/*
    Problem: Longest Consecutive Sequence
    -----------------------------
    Given an unsorted array of integers nums, return the
    length of the longest consecutive elements sequence.
    Must run in O(n) time (no sorting).

    Example:
    Input:  nums = [100,4,200,1,3,2]
    Output: 4
    (the sequence 1,2,3,4 has length 4)

    Input:  nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
    (the sequence 0,1,2,3,4,5,6,7,8 has length 9)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    unordered_set<int> numSet(nums.begin(), nums.end()); // O(1) lookup ke liye
    int longest = 0;

    for (int num : numSet)
    {
        // check karo ye number kisi sequence ka START hai ya nahi
        if (numSet.find(num - 1) == numSet.end())
        {
            int length = 1;
            int current = num;

            // jab tak agla consecutive number milta rahe, aage badho
            while (numSet.find(current + 1) != numSet.end())
            {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
        // agar num-1 set mein hai, to ye start point nahi hai -> skip
    }

    cout << longest << endl;
    return 0;
}