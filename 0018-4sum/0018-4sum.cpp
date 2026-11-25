class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int h = 0; h < n - 3; h++) {
            // 1. Skip duplicates for h
            if (h > 0 && nums[h] == nums[h - 1])
                continue;
                
            for (int i = h + 1; i < n - 2; i++) {
                // 2. Skip duplicates for i (starting from h + 1)
                if (i > h + 1 && nums[i] == nums[i - 1])
                    continue;
                    
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    // 3. Use long long to prevent integer overflow
                    long long sum = (long long)nums[h] + nums[i] + nums[j] + nums[k];
                    
                    if (sum == target) {
                        ans.push_back({nums[h], nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1])
                            j++;
                        while (j < k && nums[k] == nums[k + 1])
                            k--;
                    } else if (sum < target) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
