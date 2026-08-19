/*
    Problem: Two Sum II - Input Array Is Sorted
    -----------------------------
    Given a 1-indexed sorted array numbers in ascending 
    order, find two numbers that add up to target. Return 
    their indices (1-indexed), smaller index first. Exactly 
    one solution exists.

    Example:
    Input:  numbers = [2,7,11,15], target = 9
    Output: [1,2]
    (numbers[0] + numbers[1] = 2 + 7 = 9)

    Input:  numbers = [2,3,4], target = 6
    Output: [1,3]
    (numbers[0] + numbers[2] = 2 + 4 = 6)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;

    int left = 0;
    int right = numbers.size() - 1;

    while(left < right){
        int sum = numbers[left] + numbers[right];

        if(sum == target){
            // 1-indexed answer chahiye
            cout << "[" << left + 1 << ", " << right + 1 << "]" << endl;
            return 0;
        } else if(sum < target){
            left++; // sum badhana hai
        } else {
            right--; // sum ghatana hai
        }
    }

    cout << "No solution found" << endl;
    return 0;
}