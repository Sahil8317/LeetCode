class Solution {
public:
    long long fact(int n){
        long long ans = 1;
        for(int i= n;i>0;i--){
          ans = ans*i;  
        }
        return ans;
    }
    int numTrees(int n) {
        if(n==0)
            return 0;
        if(n==1) return 1;
    int s = 2*n-1;
    int k = 1;
    double ans = 1;
    for(int i=(n+2);i<=s;i++){
        ans *= (i/(double)(n-k));
        k++;
    }
    ans = ans*2;
    return  round(ans);
 
    }
};