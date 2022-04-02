class Solution {
public:
    bool validPalindrome(string s) {
      int i = 0,j = s.size()-1;
        int count =0;
        while(i<j){
            if(s[i]!=s[j]) {
                int p = i+1,q = j;
                int r = i,t = j-1;
                while(p<q){
                    if(s[p]!=s[q]) break; 
                    p++;
                    q--;
                  }
                while(r<t){
                  if(s[r]!=s[t]) break;
                    r++;
                    t--;
                }
                if(r>=t || p>=q) return true;
                else{
                    return false;
                }
                
            }
            i++;
            j--;
        }
       return true;
        
    }
};