class Solution {
public:
    // memorization dp
    int funct(int a,int b,int m,int n,vector<vector<int>>&dp){
        if(a==m-1 && b==n-1) return 1;
        if(a>m-1 || b>n-1)return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        dp[a][b] = funct(a+1,b,m,n,dp)+funct(a,b+1,m,n,dp);
        return dp[a][b];
    }
    
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int>(n,0));
        //return funct(0,0,m,n,dp);
        // tabulation solution
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    int left = 0,right = 0;
                    if(i>0) left =dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    dp[i][j] = left+right;
                }
            }
        }
        return dp[m-1][n-1];
    }
};