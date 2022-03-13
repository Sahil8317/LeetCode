class Solution {
public:
    bool isValid(string s) {
        map<char,char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        vector<char> v1;
        for(int i=0;s[i]!='\0';i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                v1.push_back(s[i]);
       }else{
               if(!v1.empty()){
                   if(s[i]==m[v1.back()])
                       v1.pop_back();
                   else{
                       return false;
                   }
               }else{
                   return false;
               }
            }
        }
        if(v1.empty())
            return true;
        else{
            return false;
        }
    }
                    
};