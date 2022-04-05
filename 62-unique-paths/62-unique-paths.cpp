class Solution {
public:
    int funct(int a,int b,int m,int n,vector<vector<int>>&dp){
        if(a==m-1 && b==n-1) return 1;
        if(a>m-1)return 0;
        if(b>n-1)return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        dp[a][b] = funct(a+1,b,m,n,dp)+funct(a,b+1,m,n,dp);
        return dp[a][b];
    }
    
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
              v.push_back(-1);
            }
            dp.push_back(v);
        }
       
        return funct(0,0,m,n,dp);
    }
};