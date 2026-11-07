class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        long long ans = 0;
        while (x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        return ans;
    }
};