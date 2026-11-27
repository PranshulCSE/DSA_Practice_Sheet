class Solution {
public:
    int hammingDistance(int x, int y) {
              bitset<32> xb(x), yb(y);
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += xb[i] != yb[i];
        return ans;
    }
};