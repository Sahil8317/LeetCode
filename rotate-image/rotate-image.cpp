class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        for(int i=0;i<rows;i++){
            int n = matrix[i].size();
            for(int j=0;j<n;j++){
                if(j>i){
                  swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};