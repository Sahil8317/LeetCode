class Solution {
public:
    bool checkIfPangram(string sentence) {
     unordered_map<char,int> count;
     for(char c:sentence){
         count[c]+=1;
     }
     if(count.size()==26) return true;
        return false;
    }
};