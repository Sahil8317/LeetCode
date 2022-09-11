class Solution {
public:
    
    int tradeStock(int index,int buy,int canBuy,vector<int> prices,vector<vector<vector<int>>>&dp){
        if(index==prices.size()) return 0;
        int profit = 0;
        if(dp[index][canBuy][buy]!=-1)return dp[index][canBuy][buy];
        if(buy && canBuy!=0){
            profit = max(-prices[index]+tradeStock(index+1,0,canBuy-                       1,prices,dp),0+tradeStock(index+1,1,canBuy,prices,dp));
        }else if(buy==0){
            profit = max(prices[index]+tradeStock(index+1,1,canBuy,prices,dp),0+tradeStock(index+1,0,canBuy,prices,dp));
        }
        return dp[index][canBuy][buy] =  profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(3,vector<int>(2,0)));
        //return tradeStock(0,1,2,prices,dp);
        
        // tabulation
        int n = prices.size();
        // defining base cases
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                dp[n][j][i] = 0;
            }
        }
        for(int index = n-1;index>=0;index--){
            for(int canBuy = 2;canBuy>=0;canBuy--){
                for(int buy = 0;buy<=1;buy++){
                     int profit = 0;
                     if(buy && canBuy!=0){
                           profit = max(-prices[index]+dp[index+1][canBuy-1][0] ,0+dp[index+1][canBuy][1]);
                      } else if(buy==0){
                       profit = max(prices[index]+dp[index+1][canBuy][1],0+dp[index+1][canBuy][0]);
                    }
                     dp[index][canBuy][buy] =  profit;
                
            }
        }
      }
        return dp[0][2][1];
    }
    
};
