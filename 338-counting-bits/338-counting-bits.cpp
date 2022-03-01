class Solution {
public:
    vector<int> countBits(int n) {
        int res = 0;
        vector<int> ans;
        for(int i=0;i<=n;i++){
            res =__builtin_popcount(i);
            ans.push_back(res);
        }
        return ans;
    }
};