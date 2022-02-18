class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k)
            return "0";
       int len = num.size();
       int sublen = len-k;
       int left = 0,right = len-sublen;
       string ans = "";
       for(int i=0;i<sublen;i++){
           int mmin = INT_MAX;
           int index = 0;
           right = (len-(sublen-i));
           for(int j=left;j<=right;j++){
               if((num[j]-'0')<mmin){
                   mmin = num[j]-'0';
                   index = j;
               }
           }
           ans+=to_string(mmin);
           left = index+1;     
       }
        int ind = 0;
        while(ans.size()>1){
            if(ans[ind]=='0')
                ind++;
            else
                break;
        }
        int ansLen = ans.size();
        ans = ans.substr(ind,ansLen-ind);
        if(ans=="") return "0";
        return ans;
    }
};