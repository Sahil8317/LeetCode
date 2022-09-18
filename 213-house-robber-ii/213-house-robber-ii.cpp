class Solution {
public:
    
    int fun(int index,vector<int> nums,int flag,vector<vector<int>> &dp){
        if(index>=nums.size()) return 0;
        if(index==nums.size()-1 && flag==1) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        
        int  rob = nums[index]+fun(index+2,nums,flag,dp);
        if(index==0)
            flag = 0;
        int notRob = 0+fun(index+1,nums,flag,dp);
        
        return dp[index][flag] =  max(rob,notRob);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return fun(0,nums,1,dp);
        
        // tabulatioin dp
    }
};