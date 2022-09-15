class Solution {
public:
    // one-d dp is enough as we only need to store the prev result 
    // in 2-d dp we do dp[index][prev+1] so all the time we were on the current index only.
    // better to remove as we dont need it.
    int fun(int index,int prev,vector<int> &nums,vector<int>&dp){
        if(index==nums.size())
            return 0;
        
        if(dp[prev+1]!=-1) return dp[prev+1];
        int take = 0;
        if( prev==-1 || nums[index]>nums[prev] )
           take = 1+fun(index+1,index,nums,dp);
        int notTake =0+ fun(index+1,prev,nums,dp);
        return  dp[prev+1] =  max(take,notTake);
        
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> dp(n+1,-1);
        ans = fun(0,-1,nums,dp);
        return ans;
        //  vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
        //  // base case
        // for(int index = n-1;index>=0;index--){
        //     for(int prev = n-1;prev>=-1;prev--){
        //          int take = 0;
        //         if( prev==-1 || nums[index]>nums[prev] )
        //            take = 1+dp2[index+1][index];
        //         int notTake =0+ dp2[index+1][prev];
        //          dp2[index][prev+1] =  max(take,notTake);
        //     }
        // }
        // return dp2[0][0];
    }
};