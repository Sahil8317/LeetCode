class Solution {
public:
    
    int f(int n,vector<int> &dp){
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];      
        return dp[n] = f(n-1,dp)+f(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        // return f(n,dp);  
        for(int i=0;i<=n;i++){
          if(i==0 ||i==1) dp[i] = i;
          else{
               dp[i] = dp[i-1] +dp[i-2];
            }
        }
        return dp[n];
        
    }
};