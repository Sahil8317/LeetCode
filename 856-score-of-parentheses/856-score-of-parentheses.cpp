class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<char,int>> stk;
        vector<int> ans(s.length(),0);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push({s[i],i});
            }else if(!stk.empty()){
                int index = i;
                pair<char,int> p = stk.top();
                stk.pop();
                int diff = (index-p.second);
                if(diff==1){
                    ans[index] = 1;
                }else{
                    int res = 0;
                    for(int j = p.second;j<=index;j++){
                        res+=ans[j];
                        ans[j] = 0;
                    }
                    ans[index] = res*2;
                }
            }
        }
        int fans = 0;
        for(auto &i:ans){
            fans+=i;
        }
        return fans;
        
    }
};