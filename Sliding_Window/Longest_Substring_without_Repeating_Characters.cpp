/*
    Problem: Longest Substring Without Repeating Characters
    -----------------------------
    Given a string s, find the length of the longest
    substring without repeating characters.

    Example:
    Input:  s = "abcabcbb"
    Output: 3
    ("abc" is the longest substring without repeats)

    Input:  s = "bbbbb"
    Output: 1

    Input:  s = "pwwkew"
    Output: 3
    ("wke" or "kew")
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string s = "abcabcbb";

    unordered_set<char> window; // current window ke characters
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < s.length(); right++)
    {
        // jab tak duplicate hai, left se shrink karte jao
        while (window.count(s[right]))
        {
            window.erase(s[left]);
            left++;
        }

        // ab safely current character ko window mein daal do
        window.insert(s[right]);

        // current window ka size check karo
        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}