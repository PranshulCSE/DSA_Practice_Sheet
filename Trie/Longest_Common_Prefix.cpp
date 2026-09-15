/*
    Problem: Longest Common Prefix
    -----------------------------
    Given an array of strings strs, find the longest common 
    prefix string amongst all strings. If there is no common 
    prefix, return an empty string.

    Example:
    Input:  strs = ["flower","flow","flight"]
    Output: "fl"

    Input:  strs = ["dog","racecar","car"]
    Output: ""
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    int childCount; // kितne children active hain, quickly check karने ke liye

    TrieNode() {
        isEndOfWord = false;
        childCount = 0;
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr = root;
        for(char c : word){
            int idx = c - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
                curr->childCount++;
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";

        Trie trie;
        for(string& s : strs){
            trie.insert(s);
        }

        string prefix = "";
        TrieNode* curr = trie.root;

        // jab tak exactly 1 child hai aur ye kisी word ka end nahi hai
        while(curr->childCount == 1 && !curr->isEndOfWord){
            // dhundो kaunसा single child hai
            for(int i = 0; i < 26; i++){
                if(curr->children[i] != NULL){
                    prefix += (char)('a' + i);
                    curr = curr->children[i];
                    break;
                }
            }
        }

        return prefix;
    }
};

int main(){
    vector<string> strs = {"flower", "flow", "flight"};

    Solution sol;
    string result = sol.longestCommonPrefix(strs);

    cout << result << endl; // "fl"

    return 0;
}