class Solution {
public:
    bool isValid(string s) {
       stack<char> stk;
        map<char,char> m;
        m['['] = ']';
        m['{'] = '}';
        m['('] = ')';
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]);
            }else if(stk.empty() || m[stk.top()]!=s[i]) return false;
            else{
                stk.pop();
            }
        }
        return stk.empty();
    }
                    
};