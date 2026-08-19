/*
    Problem: 3Sum
    -----------------------------
    Given an array nums, return all unique triplets 
    [nums[i], nums[j], nums[k]] such that i != j != k and 
    nums[i] + nums[j] + nums[k] == 0. The output must not 
    contain duplicate triplets.

    Example:
    Input:  nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]

    Input:  nums = [0,1,1]
    Output: []

    Input:  nums = [0,0,0]
    Output: [[0,0,0]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result;

    sort(nums.begin(), nums.end()); // step 1: sort karo
    int n = nums.size();

    for(int i = 0; i < n; i++){
        // agar current element positive hai, aage sab positive honge, sum 0 nahi ban sakta
        if(nums[i] > 0) break;

        // duplicate fixed element skip karo
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1;
        int right = n - 1;
        int target = -nums[i]; // baaki do ka sum ye hona chahiye

        while(left < right){
            int sum = nums[left] + nums[right];

            if(sum == target){
                result.push_back({nums[i], nums[left], nums[right]});

                // duplicate left aur right values skip karo
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;

                left++;
                right--;
            } else if(sum < target){
                left++; // sum badhana hai
            } else {
                right--; // sum ghatana hai
            }
        }
    }

    // print result
    for(auto &triplet : result){
        cout << "[ ";
        for(int val : triplet) cout << val << " ";
        cout << "]" << endl;
    }

    return 0;
}