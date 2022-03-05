class Solution {
    
public:
    int deleteAndEarn(vector<int>& nums) {
     int n = 10001;  
        vector<int> sum(n,0);
        for(auto &it:nums){
            sum[it]+=it;
        }
       vector<int> dp(n,0);
       dp[0] = 0;
       dp[1] = sum[1];
       for(int i=2;i<n;i++){
         int take = sum[i]+dp[i-2];
         int notTake = dp[i-1];
         dp[i] = max(take,notTake);
       }
        return dp[n-1];
    }
};