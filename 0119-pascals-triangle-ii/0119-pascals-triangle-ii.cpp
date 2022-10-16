class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(rowIndex+1,0);
        vector<int> curr(rowIndex+1,0);
        prev[0] = 1;
        for(int i = 1;i<=rowIndex;i++){
            for(int j = 0;j<i+1;j++){
                curr[j] = prev[j];
                if(j>0) curr[j]+=prev[j-1];
            }
            prev = curr;
        }
        return prev;
    }
};