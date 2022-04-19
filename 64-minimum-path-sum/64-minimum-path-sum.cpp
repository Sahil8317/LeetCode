class Solution {
public:
    // memorization 
    int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0  && j==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = grid[i][j]+f(i,j-1,grid,dp);
        int up = grid[i][j]+f(i-1,j,grid,dp);
        return dp[i][j] = min(left,up);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
       // return f(n-1,m-1,grid,dp);
        
        // tabulation
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int right = grid[i][j];
                    if(j>0) right+=dp[i][j-1];
                    else right = 1e9;
                    int down = grid[i][j];
                    if(i>0) down+=dp[i-1][j];
                    else down = 1e9;
                    dp[i][j] = min(right,down);
                }
            } 
        }
        return dp[n-1][m-1];  
    }
};