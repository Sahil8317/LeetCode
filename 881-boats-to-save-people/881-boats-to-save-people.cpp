class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int i = 0,j = p.size()-1;
        int ans = 0;
        sort(p.begin(),p.end());
        while(i<=j){
            if(p[i]+p[j]<=limit){
                i++;
                j--;
                ans++;
            }else if(p[i]+p[j]>limit){
                j--;
                ans++;
            }
        }
        return ans;
    }
};