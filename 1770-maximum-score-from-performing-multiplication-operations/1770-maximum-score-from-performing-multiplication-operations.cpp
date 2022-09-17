class Solution {
public:
    int f(int index,int n,vector<int>nums,vector<int> &multi,vector<vector<int>>&dp){
        //base case
        if(index>=multi.size()) return 0;
        if(dp[index][n]!=-1) return dp[index][n];
        int lastElement = nums[n-1]*multi[index];
        int t = nums[n-1];
        nums.pop_back();
        lastElement = lastElement+f(index+1,nums.size(),nums,multi,dp);
        nums.push_back(t);
        int firstElement = nums[0]*multi[index];
        nums.erase(nums.begin());
        firstElement = firstElement+f(index+1,nums.size(),nums,multi,dp);
        return dp[index][n] =  max(firstElement,lastElement); 
        
    }
    
     int f2(int index,int numsStart,int n,vector<int>&nums,vector<int> &multi,vector<vector<int>>&dp){
        //base case
        if(index==multi.size()) return 0;
        if(dp[index][numsStart]!=-2)return dp[index][numsStart];
        int firstElement = nums[numsStart]*multi[index]+f2(index+1,numsStart+1,n,nums,multi,dp);
        int endElement = nums[(n-(index-numsStart)-1)]*multi[index]+f2(index+1,numsStart,n,nums,multi,dp);
        return dp[index][numsStart] = max(firstElement,endElement);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
      int ans = 0;
      int n = nums.size(),m = multi.size();
      vector<vector<int>> dp(m+1,vector<int>(m+1,-2));
     
      ans = f2(0,0,n,nums,multi,dp);
      return ans;
    }
};