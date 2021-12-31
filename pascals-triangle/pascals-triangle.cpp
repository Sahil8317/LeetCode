class Solution {
public:
  
    vector<vector<int>> generate(int numRows) {
        if(numRows ==1){
            vector<vector<int>> ans {{1}};
            return ans;
        }
        vector<vector<int>> res {{1},{1,1}};
        int i = 2;
        while(i<numRows){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++){
                int num = res[i-1][j-1] + res[i-1][j];
                v.push_back(num);
        }
            v.push_back(1);
            i++;
            res.push_back(v);
        }
        return res;
    }
};