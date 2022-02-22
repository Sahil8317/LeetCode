class Solution {
public:
    int titleToNumber(string columnTitle) {
        int p=0;
        int n = columnTitle.size();
        int res=0;
        for(int i=0;i<n;i++){
            p = (n-i)-1;
            int temp = pow(26,p);
            res+=temp*(columnTitle[i]-'@');
        }
        return res;
    }
};