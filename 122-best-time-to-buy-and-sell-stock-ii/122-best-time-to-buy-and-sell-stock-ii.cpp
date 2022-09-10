class Solution {
public:
    
    
    // basically each day we have 2 choice to buy a stock or to sell a stock 
    // if you have not buyed any stock previously you can buy it but iff you have a previous stock you need to sell it before buying new stok so you need to carry a flag to see weather you have a stock or not
    // if you are holding a stock then you cant buy new one first have to sell it.
    
    
    int tradeStock(int ind,int buy,vector<int> prices,vector<vector<int>> dp){
        if(ind==prices.size()) return 0; // means profit can be zero as you havent sell any stock.or havent             buyed it
        int profit = 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            // buy can be 1 or 0
            // 1 means you can buy zero means you cannot.
            int buyIt = -prices[ind]+tradeStock(ind+1,0,prices,dp); // you move to next day with buy as 0 as ypu cannot buy again .
            // profit = sellPrice-buyPrice;
            // - indicated you have buyed a stock
            int notBuy = 0+tradeStock(ind+1,1,prices,dp);
            profit =  max(buyIt,notBuy);
        }else{
            // selling day
            int sellIt = prices[ind]+tradeStock(ind+1,1,prices,dp);
            int dontSell = 0+tradeStock(ind+1,0,prices,dp);  // you can't buy because you have sell the  existing one before.
            profit =  max(sellIt,dontSell);
        }
        return dp[ind][buy] = profit;
        
    }

    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
      // return tradeStock(0,1,prices,dp);
        // time complexity on recursize solution is 2 POWER N and space is o(N)
        // memorization also gives runtime error.
        
        // tabulation
        dp[n][0] = 0;
        dp[n][1] = 0;
        vector<int> ahead(2,0),curr(2,0);
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
                  int buyIt = -prices[ind]+ahead[0];
                  int notBuy = 0+ahead[1];
                    profit = max(buyIt,notBuy);
                }else{
                    int sellIt = prices[ind]+ahead[1];
                    int dontSell = 0+ahead[0]; 
                    profit = max(sellIt,dontSell);
                }
               curr[buy] = profit;
            }
            ahead = curr;
        } 
          return ahead[1];
        
    }
};