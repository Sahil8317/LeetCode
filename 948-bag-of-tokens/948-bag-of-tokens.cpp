class Solution {
public:
    
    
    
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //not a dp question as the order can be any not fixed.
        // greedy solution
        sort(tokens.begin(),tokens.end());
        int first=0,last = 0;
        last = tokens.size()-1;
        int ans = 0;
        int currScore = 0;
        while(first<=last){
            int tokenPower = tokens[first];
            if(power>=tokenPower){
              power-=tokenPower;
              currScore++;
              ans = max(currScore,ans);
              first++;
            }else if(currScore>=1){
                power+=tokens[last];
                currScore--;
                ans = max(currScore,ans);
                last--;
            }else{
               break;
            }
        }
        return ans;
    }
    
};