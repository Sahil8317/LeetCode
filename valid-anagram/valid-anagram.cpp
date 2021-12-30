class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m,m1;
        for(int i=0;i<s.size();i++){
            m[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            m[t[i]]--;
            if(m[t[i]]<0)
                return false;
        }
          for(auto i:m){
              if(i.second!=0)
                  return false;
          }
        return true;
        
        
    }
};