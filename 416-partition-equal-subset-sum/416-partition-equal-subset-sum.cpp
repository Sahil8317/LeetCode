class Solution {
public:
    
    bool f(int index,vector<int> &nums,int target, vector<vector<int>> &dp){
        if(index==0) return (nums[index]==target);
        if(target==0) return true;
        if(index<0) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool notTake = f(index-1,nums,target,dp);
        bool take = false;
        if(target>=nums[index]){
          take = f(index-1,nums,target-nums[index],dp);  
        }
        return dp[index][target] = take || notTake;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        vector<vector<int>> dp(201,vector<int> (1e4,-1));
        if(totalSum % 2) return false;
        int target = totalSum / 2;
        return f(nums.size()-1,nums,target,dp);
    }
};