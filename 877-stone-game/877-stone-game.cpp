class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int first = 0,last = piles.size()-1;
        int alice = 0,bob = 0;
        bool flag = true;
        while(first<=last){
            if(flag){
                //alice turn
            if(piles[first]>piles[last]){
                alice+=piles[first];
                first++;
            }else{
                alice+=piles[last];
                last--;
            }
            flag = false;
          }else{
               // bob turn 
               if(piles[first]<piles[last]){
                   bob+=piles[first];
                   first++;
               } else{
                   bob+=piles[last];
                   last--;
                }
                flag = true;
          }
        }
        return alice>bob;
    }
};