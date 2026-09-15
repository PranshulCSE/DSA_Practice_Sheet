/*
    Problem: Count Prefix and Suffix Pairs I
    -----------------------------
    Given an array of strings words, count the number of
    valid pairs (i, j) where i < j, and words[i] is both a
    prefix and a suffix of words[j].

    Example:
    Input:  words = ["a","aba","ababa","aa"]
    Output: 4
    (pairs: (0,1),(0,2),(0,3),(1,2))
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    // check karo str1, str2 ka prefix bhi hai aur suffix bhi
    bool isPrefixAndSuffix(string &str1, string &str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 > len2)
            return false; // str1 lambी hai to prefix/suffix ho hi nahi sakती

        // prefix check: str2 ke shuru ke len1 characters str1 ke barabar hain kya
        bool isPrefix = (str2.substr(0, len1) == str1);

        // suffix check: str2 ke aakhri len1 characters str1 ke barabar hain kya
        bool isSuffix = (str2.substr(len2 - len1) == str1);

        return isPrefix && isSuffix;
    }

public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<string> words = {"a", "aba", "ababa", "aa"};

    Solution sol;
    int result = sol.countPrefixSuffixPairs(words);

    cout << result << endl; // 4

    return 0;
}