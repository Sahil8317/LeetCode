class Solution {
public:
// dp+dfs question0 
    int f(vector<int> nums,int target,vector<int> &dp){
        if(dp[target]!=-1) return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target)
              ans+=f(nums,target-nums[i],dp);
        }
        dp[target] = ans;
        return ans;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        dp[0] = 1;
        return f(nums,target,dp);
    }
};