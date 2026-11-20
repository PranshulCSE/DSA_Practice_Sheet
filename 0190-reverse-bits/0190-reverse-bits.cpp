class Solution {
public:
    int reverseBits(int n) {
        int result = 0; // This will hold our reversed number

        // Loop 32 times because an int has 32 bits
        for (int i = 0; i < 32; i++) {
            // 1. Shift result to the left by 1 to make room for the next bit
            result = result << 1;

            // 2. Get the last bit of n (n & 1) and add it to result
            result = result | (n & 1);

            // 3. Shift n to the right by 1 to move to the next bit
            n = n >> 1;
        }

        return result;
    }
};