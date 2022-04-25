class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>> &grid,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi = INT_MIN;
        for(int p=-1;p<=1;p++){
            for(int q=-1;q<=1;q++){
                if(j1==j2){
                     maxi = max(maxi,grid[i][j1]+f(i+1,j1+p,j2+q,grid,n,m,dp));
                }else{
                     maxi = max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+p,j2+q,grid,n,m,dp));
                }
            }
        }
        return  dp[i][j1][j2] = maxi;  
        
    }
      
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,n,m,dp);
    }
};