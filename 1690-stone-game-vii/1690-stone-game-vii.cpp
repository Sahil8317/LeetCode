class Solution {
public:
    
    
    //explanation
    // as alice always wants to 
   int f(int s,int e,int sum,int flag,vector<int> &stones,vector<vector<int>> &dp){
       if(s==e) return 0; // as this will return 0 last stone picked sum will be zero as no elements remain in array.
       if(dp[s][e]!=-1) return dp[s][e];
       if(flag){
         // alice turn 
         int left =sum-stones[s]+f(s+1,e,sum-stones[s],0,stones,dp);
         int right = sum-stones[e]+f(s,e-1,sum-stones[e],0,stones,dp);
           return dp[s][e] =  max(left,right);
       }else{
          // bob turn
           // -sum as from here the call will go back to alice and we have to 
           // take the difference so its aliceturn - bob turn 
           // for alice the above diff should be maximum and for bob this should be minimun
           // hence alice turn has max and bob turn has min.
           // try to run certain calls you will get why there is a minuns in bob.
           //If the current player is Alice: Difference = Current Score - Difference returned by Bob
            //If the current player is Bob: Difference = Current Score - Difference returned by Alice
           int left = f(s+1,e,sum-stones[s],1,stones,dp)-(sum-stones[s]);
           int right = f(s,e-1,sum-stones[e],1,stones,dp)- (sum-stones[e]);
           return dp[s][e] = min(left,right);
      }
   }
    
    int stoneGameVII(vector<int>& stones) {
        int sum =0;
        for(int i:stones){
            sum+=i;
        }
        int n = stones.size();
       // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,sum,1,stones,dp);
       
    }
};