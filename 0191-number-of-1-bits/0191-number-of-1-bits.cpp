class Solution {
public:
    int hammingWeight(int n) {
        int num=n;
     int sum = 0;
      while (num != 0) {
                // we have to count 1's in binary representation of i, therefore
                // % 2
                sum += num % 2;
                num = num / 2;
            }
            return sum;   
    }
};