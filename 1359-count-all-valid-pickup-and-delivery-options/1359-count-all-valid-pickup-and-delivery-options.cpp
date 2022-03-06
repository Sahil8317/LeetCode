class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long long ans  =1;
        for(int i=1;i<=n;i++){
            //for picking i order the number of ways is i!
            ans = (ans*i)%mod;
            // for delivering i ordr the number of ways is 2*i-1
            ans = (ans*(2*i-1))%mod;
        }
        return ans;
    }
};