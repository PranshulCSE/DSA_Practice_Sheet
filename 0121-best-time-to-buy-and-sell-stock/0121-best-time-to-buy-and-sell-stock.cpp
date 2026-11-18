class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Sabse Pehle wala Buy kro assuming that ki yahi sbse sasta hai
        int buy=prices[0];

        int profit=0;

        // Ek loop jo check krega kisme Profit jada hai

        for(int i=1;i<prices.size();i++){
            // Agar Sasta hai to khareed lo 
            if(prices[i]<buy){
                buy=prices[i];
            } 
            // Agar Proft jyada hai to bech do
            else if(prices[i]-buy>profit){
                profit = prices[i]-buy;
            }
        }
            return profit;
    }
};