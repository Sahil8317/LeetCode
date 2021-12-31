class Solution {
public:
    void setZeroes(vector<vector<int>>&matrix) {
        vector<int> v;
        for(auto &i:matrix){
            int rowL = i.size();
            bool iszero = false;;
            for(int j=0;j<rowL;j++){
                if(i[j]==0){
                    iszero = true;
                    for(int k=0;k<j;k++){
                        if(i[k]==0)
                            break;
                        i[k]=0;
                    }
                    v.push_back(j);
                }
                 if(i[j]!=0 && iszero)
                    i[j]=0;
            }
        }
        for(int &i:v){
            for(auto &j:matrix){
                j[i] = 0;
            }
        }
        
    }
};