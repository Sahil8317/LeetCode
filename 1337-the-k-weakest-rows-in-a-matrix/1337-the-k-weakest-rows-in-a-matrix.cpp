class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       int n = mat.size();
        vector<pair<int,int>> sol;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) count++;
            }
            sol.push_back({count,i});
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(sol[j].first>sol[j+1].first){
                    pair<int,int> temp = sol[j];
                    sol[j] = sol[j+1];
                    sol[j+1] = temp;
                }
            }
        }
        vector<int> ans;
        for(auto i:sol){
            k--;
            ans.push_back(i.second);
            if(k==0) break;
        }
        return ans;
    }
};