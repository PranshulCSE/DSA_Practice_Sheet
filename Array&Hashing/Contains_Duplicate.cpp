/*
    Problem: Contains Duplicate
    -----------------------------
    Given an array of integers, return true if any value
    appears at least twice in the array, and return false
    if every element is distinct.

    Example:
    Input:  nums = [1,2,3,1]
    Output: true
    (because 1 appears twice)

    Input:  nums = [1,2,3,4]
    Output: false
    (all elements are unique)
*/

#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> nums = {1,2,3,4,5};
    unordered_set<int> s;
    for(int num : nums){
        if(s.find(num) != s.end()){
            cout << "true" << endl;
            return 0;
        }
        s.insert(num);
    }
    cout << "false" << endl;
    return 0;
}