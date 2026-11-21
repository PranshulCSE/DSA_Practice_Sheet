class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Har number ki frequency (kitni baar aaya hai) store karne ke liye map
        unordered_map<int, int> freq;

        // Step 1: Har number ka count badhao
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Jin numbers ka count 1 hai, unhe answer vector mein daal do
        vector<int> ans;
        for (auto it : freq) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
