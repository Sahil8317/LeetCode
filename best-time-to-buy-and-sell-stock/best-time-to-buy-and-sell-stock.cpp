class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b = n-1,s=n-1;
        int maxp=0;
        while(b>=0){
            int p = prices[s]-prices[b];
            int k=0;
            if(p==0){
                b--;
            }else{
                if(p<0){
                    s = b;
                    b--;
                }else{
                    if(p>maxp){
                    k = b;
                    b--;
                    maxp = p;
                    }else{
                        b--;
                    }
                }
            }
            
        }
        return maxp;
    }
};