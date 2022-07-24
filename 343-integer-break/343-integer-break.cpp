class Solution {
public:
    // memorization
    int f(int index,int n,vector<int> &arr,vector<vector<int>> &dp){
        if(index==0){
            return 1;
        }
        if(dp[index][n]!=-1) return dp[index][n];
        int notTake = 1*f(index-1,n,arr,dp);
        int take = INT_MIN;
        if(arr[index]<=n){
            take = f(index,n-arr[index],arr,dp)*arr[index];
        }
        return dp[index][n] = max(take,notTake);
    }
    int integerBreak(int n) {
        vector<int> arr;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=1;i<n;i++)
            arr.push_back(i);
        
        return f(n-2,n,arr,dp);
        //Tabulation
        //base case
        
        // for(int N = 0;N<=n;N++){
        //     dp[0][N] = 1;
        // }
        // for(int index = 1;index<n;index++){
        //     for(int N = 0;N<=n;N++){
        //         int notTake = (dp[index-1][N])*1;
        //         int take =INT_MIN;
        //         if(arr[index]<=N)
        //             take = (dp[index][N-arr[index]])*arr[index];
        //         dp[index][N] = max(take,notTake);
        //     }
        // }
        // return dp[n-1][n];
    }
};