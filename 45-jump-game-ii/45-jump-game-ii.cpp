class Solution {
public:
    
    int f(int index,vector<int>&nums,vector<int> &dp){
        if(index==nums.size()-1) return 0;
        int ans = 10000;
        if(dp[index]!=-1)return dp[index];
        for(int i=1;i<=nums[index];i++){
           if(index+i < nums.size()){
           int val = f(i+index,nums,dp)+1; 
           ans = min(ans,val);
           }else
               break;
        }
        return dp[index] = ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int ans = f(0,nums,dp);  
        return ans;
    }
};