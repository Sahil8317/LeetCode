class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int i = 0;
        int s = path.length();
        while(i<path.length()){
            if(path[i]=='/'){
                while(i<s && path[i]=='/'){
                    i++;
                }
                string d = "";
                while(i<s && path[i]!='/'){
                    d+=path[i];
                    i++;
                }
                if(d=="."){
                    d = "";
                }else if(d==".."){
                    if(!stk.empty()){
                        stk.pop();
                    }
                }else if(d=="..."){
                    stk.push(d);
                }else if(d!=""){
                    stk.push(d);
                }
            }
        }
        string res = "/";
        vector<string> ar;
        
        while(!stk.empty()){
            ar.push_back(stk.top());
            stk.pop();
        }
        reverse(ar.begin(),ar.end());
        for(int i=0;i<ar.size();i++){
             res+=ar[i];
            if(i<ar.size()-1) res+='/';
        }
        return res;
    }
    
};