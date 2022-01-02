class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<rows-1;i++){
            if(target<matrix[i][0])
                return false;
            if(target>=matrix[i][0] && target<matrix[i+1][0]){
                for(int j=0;j<col;j++){
                    if(matrix[i][j]==target)
                        return true;
                }
            }
        }
        if(target>=matrix[rows-1][0] && target<=matrix[rows-1][col-1]){
            for(int j=0;j<col;j++){
                if(matrix[rows-1][j]==target)
                    return true;
            }
}   
        return false;
    }
};