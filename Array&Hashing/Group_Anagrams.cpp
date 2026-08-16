/*
    Problem: Group Anagrams
    -----------------------------
    Given an array of strings strs, group the anagrams
    together. You can return the answer in any order.

    Example:
    Input:  strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    (eat, tea, ate are anagrams of each other -> one group)
    (tan, nat are anagrams of each other -> one group)
    (bat has no match -> its own group)
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    unordered_map<string, vector<string>> mp; // sorted-key -> group of original strings

    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end()); // key banayi: sorted version of string

        // is key ke bucket mein original string daal do
        mp[key].push_back(s);
    }

    // ab result print karte hain, har key ka group
    for (auto &pair : mp)
    {
        cout << "[ ";
        for (string s : pair.second)
        {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}