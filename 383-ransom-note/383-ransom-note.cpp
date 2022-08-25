class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> str1;
        for(char c:magazine){
            str1[c]+=1;
        }
       for(char c:ransomNote){
           if(str1[c]==0) return false;
          str1[c]--;
       }
    return true;
    }
};