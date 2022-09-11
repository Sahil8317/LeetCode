class Solution {
public:
    
    int tradeStock(int index,int canBuy,int buy,vector<int> &prices,vector<vector<vector<int>>>&dp){
        if(index==prices.size()) return 0;
        int profit = 0;
        if(dp[index][canBuy][buy]!=-1)return dp[index][canBuy][buy];
        if(buy && canBuy!=0){
            int buyIt = -prices[index]+tradeStock(index+1,canBuy-1,0,prices,dp);
            int notBuy = 0+tradeStock(index+1,canBuy,1,prices,dp);
            profit = max(buyIt,notBuy);
        }else if(buy==0){
            int sellIt = prices[index]+tradeStock(index+1,canBuy,1,prices,dp);
            int notSell = 0+tradeStock(index+1,canBuy,0,prices,dp);
            profit = max(sellIt,notSell);
        }
        return dp[index][canBuy][buy] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return tradeStock(0,k,1,prices,dp);
        
        
    }
};