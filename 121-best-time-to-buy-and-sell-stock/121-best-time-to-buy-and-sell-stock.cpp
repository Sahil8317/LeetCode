class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int cost = prices[i]-minPrice;
            profit = max(profit,cost);
            minPrice = min(minPrice,prices[i]);
            
        }
        return profit;
    }
};