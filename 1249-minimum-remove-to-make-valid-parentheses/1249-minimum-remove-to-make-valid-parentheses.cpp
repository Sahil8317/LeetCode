class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> stk;
        int n = s.length();
        vector<int> ele;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]==')'){
            if(s[i]=='(') stk.push({'(',i});
            else if(s[i]==')' && !stk.empty() && stk.top().first=='(') stk.pop();
            else{
               stk.push({s[i],i});
            }
            }
        }
        string ans = "";
            while(!stk.empty()){
                pair<char,int> p = stk.top();
                cout<<p.second<<endl;
                s[p.second] = '*';
                stk.pop();
            }
         for(int i=0;i<n;i++){
                if(s[i]!='*')
                  ans+=s[i];
        }
        return ans;
    }
};