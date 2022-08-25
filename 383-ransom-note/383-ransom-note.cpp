class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> str1,str2;
        for(char c:ransomNote){
            str1[c]+=1;
        }
        for(char c:magazine){
            str2[c]+=1;
        }
       for(auto m:str1){
          if (str2[m.first]<m.second)
              return false;
       }
    return true;
    }
};