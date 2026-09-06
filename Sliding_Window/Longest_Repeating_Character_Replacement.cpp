/*
    Problem: Longest Repeating Character Replacement
    -----------------------------
    Given a string s and integer k, you can replace at most 
    k characters in s with any uppercase letter. Return the 
    length of the longest substring containing the same 
    letter after replacements.

    Example:
    Input:  s = "ABAB", k = 2
    Output: 4
    (replace 2 chars to make "AAAA" or "BBBB")

    Input:  s = "AABABBA", k = 1
    Output: 4
    ("AABA" -> replace one char -> "AAAA")
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    string s = "AABABBA";
    int k = 1;

    unordered_map<char,int> freq;
    int left = 0;
    int maxFreq = 0;
    int maxLen = 0;

    for(int right = 0; right < s.length(); right++){
        freq[s[right]]++;
        maxFreq = max(maxFreq, freq[s[right]]); // sबसे common character ka count

        // agar window invalid ho gaya (k se zyada replace chahiye)
        if((right - left + 1) - maxFreq > k){
            freq[s[left]]--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    cout << maxLen << endl;
    return 0;
}