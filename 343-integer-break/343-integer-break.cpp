class Solution {
public:
    
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
    }
};