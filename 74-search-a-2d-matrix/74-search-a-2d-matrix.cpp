class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int high = (rows*col)-1;
        int low = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid/col][mid%col]==target)
                return true;
            if(matrix[mid/col][mid%col]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};