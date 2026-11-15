class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int largest = nums[n - 1];
        int second_largest = nums[n - 2];

        return (largest - 1 )*(second_largest - 1);
    }
};