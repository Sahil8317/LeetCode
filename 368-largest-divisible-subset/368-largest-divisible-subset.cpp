class Solution {
public:
    
    
//     void f(int index,int prevIndex,vector<int>&nums,vector<int>ans,vector<vector<int>> &fans){
//         if(index>=nums.size()){
//             fans.push_back(ans);
//             return ;
//         }
//         if(prevIndex==-1 || nums[index]%nums[prevIndex]==0 || nums[prevIndex]%nums[index]==0){
//             ans.push_back(nums[index]);
//             f(index+1,index,nums,ans,fans);
//             ans.pop_back();
//         }
//         //not take case or skipping case
//         f(index+1,prevIndex,nums,ans,fans);
//     }
    
    vector<int> check(int i,vector<int>nums,map<int,vector<int>>&dp){
        vector<int> ans;
        if(dp.find(i)!=dp.end()) return dp[i];
        for(int j = i+1;j<nums.size();j++){
            if(nums[j]%nums[i]==0){
             auto res = check(j,nums,dp);
             if(res.size()>ans.size()) ans = res;
            }
        }
        ans.push_back(nums[i]);
        dp[i] = ans;
        return ans;
        
    }
        
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<int> sol;
        vector<int> fans;
        map<int,vector<int>> dp;
       for(int i=0;i<nums.size();i++){
           auto res = check(i,nums,dp);
           if(res.size()>fans.size()) fans = res;
       }
        return fans;
    }
};