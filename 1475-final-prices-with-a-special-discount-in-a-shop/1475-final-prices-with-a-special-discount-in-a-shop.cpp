class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
     stack<int> stk;
        vector<int> ans;
        for(int i=prices.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top() > prices[i] ){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(prices[i]);
            }else{
                ans.push_back(prices[i]-stk.top());
            }
            stk.push(prices[i]);
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
    
};