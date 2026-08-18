/*
    Problem: Container With Most Water
    -----------------------------
    Given an array height where height[i] represents a
    vertical line, find two lines that together with the
    x-axis form a container that holds the most water.
    Area = min(height[i], height[j]) * (j - i)

    Example:
    Input:  height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    (lines at index 1 and 8: min(8,7)*(8-1) = 7*7 = 49)

    Input:  height = [1,1]
    Output: 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int width = right - left;
        int currHeight = min(height[left], height[right]);
        int currArea = width * currHeight;

        maxArea = max(maxArea, currArea);

        // jo height chhoti hai, usी pointer ko andar move karo
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << maxArea << endl;
    return 0;
}