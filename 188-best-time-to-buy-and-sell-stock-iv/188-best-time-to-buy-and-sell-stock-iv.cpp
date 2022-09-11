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
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        //return tradeStock(0,k,1,prices,dp);
        
        // tabulation
        int n = prices.size();
        for(int i=0;i<=k;i++){
            for(int j=0;j<=1;j++){
                dp[n][i][j]= 0;
            }
        }
        
        for(int index = n-1;index>=0;index--){
            for(int canBuy = k;canBuy>=0;canBuy--){
                for(int buy = 0;buy<=1;buy++){
                    int profit = 0;
                    if(buy && canBuy!=0){
                       profit = max(-prices[index]+dp[index+1][canBuy-1][0],0+dp[index+1][canBuy][1]); 
                    }else if(buy==0){
                        profit = max(prices[index]+dp[index+1][canBuy][1],0+dp[index+1][canBuy][0]);
                    }
                    dp[index][canBuy][buy] = profit;
                }
            }
        }
        return dp[0][k][1];
        
        
    }
};