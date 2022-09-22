class Solution {
public:
    
    
    int f(int index,vector<int>&nums,int r,vector<vector<int>> &dp){
        if(index>=nums.size()) {
            if(r==0) return 0;  // as we are returning always a greater number
            return -1000000;  // if the remainder is not equal to zero then there is no need of taking that result.
        } 
        if(dp[index][r]!=-1) return dp[index][r];
         int take = nums[index]+ f(index+1,nums,(r+nums[index])%3,dp);
         int notTake = 0+ f(index+1,nums,r,dp);
         return dp[index][r] =  max(take,notTake);
    }
    
    int maxSumDivThree(vector<int>& nums) {
         vector<vector<int>> dp(nums.size(),vector<int>(4,-1));
         int ans = f(0,nums,0,dp);
         return ans;
    }
    
};