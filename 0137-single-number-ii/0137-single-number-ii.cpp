class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Unique numbers store karne ke liye set (duplicates hat jayenge)
        unordered_set<int> s;
        
        // Overflow se bachne ke liye long long use kiya hai
        long long sum = 0;

        // Pure array ka total sum nikaalo aur saare elements set mein daalo
        // Example: agar array [2, 2, 2, 5] hai, toh sum = 11 aur set = {2, 5}
        for (int c : nums) {
            s.insert(c);
            sum += c;
        }

        // Sirf unique numbers ka sum nikaalo
        // Example: setSum = 2 + 5 = 7
        long long setSum = 0;
        for (int c : s) {
            setSum += c;
        }

        // Logic: Har number 3 baar aata hai, bas ek number 1 baar aata hai.
        // Agar sabhi unique numbers 3 baar aate, toh total sum hota (3 * setSum).
        // Ismein se actual 'sum' minus karne par single number ka double (2x) bachta hai.
        // Example: (3 * 7 - 11) / 2 = (21 - 11) / 2 = 10 / 2 = 5
        return (int)((3 * setSum - sum) / 2);
    }
};
