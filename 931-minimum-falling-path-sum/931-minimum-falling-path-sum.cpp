class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp){
        if(j<0 || j>=m) return 1e8;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = matrix[i][j]+f(i-1,j,matrix,n,m,dp);
        int leftUp = matrix[i][j]+f(i-1,j-1,matrix,n,m,dp);
        int rightUp = matrix[i][j]+f(i-1,j+1,matrix,n,m,dp);
        return dp[i][j] = min(up,min(leftUp,rightUp));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            mini = min(mini,f(n-1,i,matrix,n,m,dp));
        }
        return mini;
    }
};