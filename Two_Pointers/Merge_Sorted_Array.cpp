/*
    Problem: Merge Sorted Array
    -----------------------------
    Given two sorted arrays nums1 and nums2, merge nums2 
    into nums1 as one sorted array in-place. nums1 has size 
    m+n where the first m elements are valid and the last n 
    are 0 (placeholder space for nums2's elements).

    Example:
    Input:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]

    Input:  nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    int i = m - 1;       // nums1 ke valid elements ka last index
    int j = n - 1;       // nums2 ka last index
    int k = m + n - 1;   // nums1 ka sabse aakhri position

    // dono arrays ke end se compare karke bada element peeche se bharte jao
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // agar nums2 mein kuch bacha hai, use bhi copy kar do
    // (agar nums1 mein bacha hai to already sahi jagah pe hai, kuch karna nahi)
    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    cout << "[ ";
    for(int val : nums1){
        cout << val << " ";
    }
    cout << "]" << endl;

    return 0;
}