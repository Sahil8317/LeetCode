class StockSpanner {
private:
    stack<pair<int,int>> stk;
    int index;
public:
    StockSpanner() {
      index = -1;
    }
    
    int next(int price){
        index+=1;
        int ans = 0;
        while(!stk.empty() && stk.top().second<=price){
            stk.pop();
        }
        if(stk.empty()){
           ans = index - (-1);
        }else{
            ans = index - (stk.top().first);
        } 
        stk.push({index,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */