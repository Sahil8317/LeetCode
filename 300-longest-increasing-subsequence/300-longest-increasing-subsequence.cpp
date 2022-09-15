class Solution {
public:
    
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
//         for(int prev=0;prev<=n;prev++){
//             dp[n][prev] = 0;
//         }
        
       
        
    }
};