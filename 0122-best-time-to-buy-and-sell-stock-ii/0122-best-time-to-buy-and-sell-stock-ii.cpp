class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n;i++){
            int profit=nums[i]-nums[i-1];
            if(profit>0) ans+=profit;
        }
        return ans;
    }
};