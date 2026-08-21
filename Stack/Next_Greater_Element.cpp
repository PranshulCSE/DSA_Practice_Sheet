/*
    Problem: Next Greater Element I
    -----------------------------
    Given two arrays nums1 and nums2 (nums1 is a subset of 
    nums2), for each element in nums1, find its "Next Greater 
    Element" in nums2 (the first greater number to its right 
    in nums2). If none exists, output -1.

    Example:
    Input:  nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]
    (4 has nothing after it in nums2 -> -1)
    (1 -> next greater in nums2 is 3)
    (2 -> nothing greater after it -> -1)

    Input:  nums1 = [2,4], nums2 = [1,2,3,4]
    Output: [3,-1]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    unordered_map<int,int> nextGreater; // element -> uska next greater element
    stack<int> st; // monotonic decreasing stack

    for(int num : nums2){
        // jab tak current number stack ke top se bada hai, settle karte jao
        while(!st.empty() && num > st.top()){
            nextGreater[st.top()] = num; // top ka next greater mil gaya = current num
            st.pop();
        }
        st.push(num); // current ko push kar do
    }

    // jo bache stack mein reh gaye, unka next greater nahi mila -> -1
    while(!st.empty()){
        nextGreater[st.top()] = -1;
        st.pop();
    }

    // ab nums1 ke har element ke liye map se answer nikal lo
    vector<int> result;
    for(int num : nums1){
        result.push_back(nextGreater[num]);
    }

    cout << "[ ";
    for(int val : result) cout << val << " ";
    cout << "]" << endl;

    return 0;
}