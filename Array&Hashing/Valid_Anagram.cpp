/*
    Problem: Valid Anagram
    -----------------------------
    Given two strings s and t, return true if t is an
    anagram of s, and false otherwise.
    (An anagram means same characters with same frequency,
    just rearranged)

    Example:
    Input:  s = "anagram", t = "nagaram"
    Output: true

    Input:  s = "rat", t = "car"
    Output: false
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s = "anagram";
    string t = "nagarfm";

    // agar length hi different hai to anagram ho hi nahi sakta
    if (s.length() != t.length())
    {
        cout << "false" << endl;
        return 0;
    }

    vector<int> freq(26, 0); // sirf lowercase a-z ke liye

    // s ke har character pe count badhao
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    // t ke har character pe count ghatao
    for (char c : t)
    {
        freq[c - 'a']--;
    }

    // agar koi bhi count non-zero raha, matlab mismatch hai
    for (int val : freq)
    {
        if (val != 0)
        {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "true" << endl;
    return 0;
}