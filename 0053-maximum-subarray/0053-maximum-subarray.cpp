class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n=nums.size();
        int mx=nums[0];
        int sum=nums[0];

        for(int i=1;i<n;i++){
            int next=nums[i];

            // finding if sum is greater
            sum=max(sum+next, next);
            mx=max(mx,sum);
        }
        return mx;
    }
};