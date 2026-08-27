/*
    Problem: Random Pick with Weight
    -----------------------------
    Given an array of weights w, design pickIndex() that
    randomly picks an index in proportion to its weight.

    Example:
    w = [1,3]
    -> total weight = 4
    -> index 0 picked with probability 1/4
    -> index 1 picked with probability 3/4
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution
{
private:
    vector<int> prefixSum;

public:
    Solution(vector<int> &w)
    {
        int sum = 0;
        for (int weight : w)
        {
            sum += weight;
            prefixSum.push_back(sum); // prefix sum bana rahe hain
        }
    }

    int pickIndex()
    {
        int total = prefixSum.back(); // total weight sum

        // random number generate karo 1 se total ke beech (inclusive)
        int target = (rand() % total) + 1;

        // binary search: pehla index dhundo jaha prefixSum[i] >= target
        int left = 0;
        int right = prefixSum.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (prefixSum[mid] < target)
            {
                left = mid + 1; // aage badho, ye zone chhota hai
            }
            else
            {
                right = mid; // ye ya isse pehle wala answer ho sakta hai
            }
        }

        return left;
    }
};

int main()
{
    srand(time(0)); // random seed set karo

    vector<int> w = {1, 3};
    Solution solution(w);

    // test karte hain 10 baar pick karke
    for (int i = 0; i < 10; i++)
    {
        cout << solution.pickIndex() << " ";
    }
    cout << endl;

    return 0;
}