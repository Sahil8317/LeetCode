class Solution {
public:
    string reverseWords(string s) {
    int len = s.length() - 1;
    int i =0;
    int j = len;
    char ch = s[i];
    while(ch==' '){
        i++;
        ch = s[i];
    }
    ch = s[j];
    while(ch==' '){
        j--;
        ch = s[j];
    }
    string ans ="";
    while(j>=i){
        char ch = s[j];
        string r = "";
        while(ch!=' '){
            r+=ch;
            j--;
            if(j<i){
                break;
            } 
              ch = s[j];
        }
        reverse(r.begin(),r.end());
        if(r!=""){
            ans+=r;
            if(j<i){
              ans+="";  
            }else{
             ans+=" ";   
            }
            
            r="";
        }
        j--;
    }
      return ans;
}
    
};