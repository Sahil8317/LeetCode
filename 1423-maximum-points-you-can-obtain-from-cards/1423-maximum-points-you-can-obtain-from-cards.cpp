class Solution {
public:
    int f(int index,int sIndex,int k,vector<int>&cardPoints,vector<vector<int>> &dp){
        if(index==k) return 0;
        if(dp[index][sIndex]!=-1) return dp[index][sIndex];
        int takeFromStart =cardPoints[sIndex]+ f(index+1,sIndex+1,k,cardPoints,dp);
        int takeFromEnd = cardPoints[cardPoints.size()-(index-sIndex)-1]+f(index+1,sIndex,k,cardPoints,dp);
        return dp[index][sIndex] =  max(takeFromStart,takeFromEnd);
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
       // vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
//         vector<int> ahead(k+1,0), curr(k+1,0);
//        // return f(0,0,k,cardPoints,dp);
//         for(int index=k-1;index>=0;index--){
//             for(int sIndex=0;sIndex<k;sIndex++){  // k as atmax you can take only k elements not more than that.
//                 int end = n-(index-sIndex)-1;
//                  if(end>=n || end<0) break;
//                  int takeFromStart = cardPoints[sIndex]+ ahead[sIndex+1];
//                  int takeFromEnd = cardPoints[end]+ahead[sIndex];
//                  curr[sIndex] =  max(takeFromStart,takeFromEnd);
//             }
//             ahead = curr;
//         }
        
//        return  ahead[0];
       // the above solution(tabulation dp) gives a time complecity of o(k2) and space of o(k) acceptable in an interview.
        
        //a better solution exits which gives result in o(k)time and space complexity of o(k).
        // to take k elements from array of size n there are 3 possibilities
        //1. take all k elements from front/left only 
        //2. take all k elements from last/right only
        //3. take all p elemets from left and take k-p elements from right side.
        
        vector<int> dp(k+1,0);
        // 2nd possibility
        for(int i=n-1;i>=n-k;i--){
            dp[0]+=cardPoints[i];
        }
        int ans = dp[0];
        for(int p = 1;p<k+1;p++){
            dp[p] = cardPoints[p-1]+dp[p-1]-cardPoints[n-k+p-1];  // basically take p elements from front and
                                                           // then all elements from back - one element of right 
            ans = max(ans,dp[p]);
        }
        return ans;
     
    }
};