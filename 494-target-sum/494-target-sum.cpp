class Solution {
public:
    
    int f(int index,vector<int> &nums,int target,map<pair<int,int>,int> &dp){
        if(index==0){
            return (target+nums[index]==0)+(target-nums[index]==0);  // in some of the test case taking the index element in both the cases will give you the answer.
        }
        if(dp.find({index,target})!=dp.end()) return dp[{index,target}];
        int notTake = f(index-1,nums,target+nums[index],dp);
        int take = f(index-1,nums,target-nums[index],dp);
        
        return dp[{index,target}] = notTake+take;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> dp;
        return f(nums.size()-1,nums,target,dp);
    }
};