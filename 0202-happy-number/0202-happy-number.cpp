class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1){
            if(seen.find(n)!=seen.end()){
                return false;
            }
            seen.insert(n);
            int sum=0;
            while(n){
                int dig=n%10;
                sum+=dig*dig;
                n/=10;
            }
            n=sum;
        }
        return true;
    }
};