/*
    Problem: Subarray Product Less Than K
    -----------------------------
    Given an array of positive integers nums and an integer 
    k, return the count of contiguous subarrays where the 
    product of all elements is strictly less than k.

    Example:
    Input:  nums = [10,5,2,6], k = 100
    Output: 8
    (valid subarrays: [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6])

    Input:  nums = [1,2,3], k = 0
    Output: 0
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;

    if(k <= 1){
        cout << 0 << endl;
        return 0;
    }

    int left = 0;
    long long product = 1;
    int count = 0;

    for(int right = 0; right < nums.size(); right++){
        product *= nums[right]; // naya element multiply karo

        // product k se bada/barabar ho gaya, shrink karo
        while(product >= k){
            product /= nums[left];
            left++;
        }

        // is window ke andar 'right' pe end hone wali sab subarrays valid hain
        count += (right - left + 1);
    }

    cout << count << endl;
    return 0;
}