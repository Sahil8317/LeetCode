class Solution {
public:
    bool isSubsequence(string s, string t) {
        int first = 0,second = 0;
        if(s.size()>t.size()) return false;
        int i = 0;
        for(;i<s.size();i++){
        int c = s[i];
        bool flag = true;
        while(flag && second<t.size()){
            if(t[second]==c){
              flag = false;  
            }
            second++;
        }
       if(flag) return false;
    }
    if(i==s.size()) return true;
    return false;
 }
};