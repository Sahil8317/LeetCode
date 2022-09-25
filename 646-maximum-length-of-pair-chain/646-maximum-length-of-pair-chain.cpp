class Solution {
public:
    
    // static bool cmp(vector<int>&v1,vector<int>&v2){
    //     return v1[1]<v2[0];
    // }
    
    int f(int index,int prev,vector<vector<int>> &pairs,vector<vector<int>>&dp){
        if(index==pairs.size()) return 0;
        int take = 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        if(prev==-1 || pairs[index][0]>pairs[prev][1])
            take = f(index+1,index,pairs,dp)+1;
        int notTake = f(index+1,prev,pairs,dp);
        return dp[index][prev+1] = max(take,notTake);
    }
    
   
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        // for(auto vec:pairs){
        //     cout<<vec[0]<<" "<<vec[1]<<endl;
        // }
        vector<vector<int>> dp(pairs.size()+1,vector<int>(pairs.size()+1,-1));
        return f(0,-1,pairs,dp);
    }
};