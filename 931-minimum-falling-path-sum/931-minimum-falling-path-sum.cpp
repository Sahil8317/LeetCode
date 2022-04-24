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
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int down = matrix[i][j]+dp[i-1][j];
                int downLeft = matrix[i][j];
                if(j>0) downLeft+=dp[i-1][j-1];
                else downLeft = 1e8;
                int downRight = matrix[i][j];
                if(j+1<m) downRight+= dp[i-1][j+1];
                else downRight = 1e8;
                dp[i][j] = min(down,min(downLeft,downRight));
            }
        }    
        for(int i=0;i<m;i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};