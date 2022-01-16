class Solution {
public:
    
    void findComb(vector<int> &can,int target,vector<vector<int>> &ans,vector<int>&res,int index){
        if(target==0){
            sort(res.begin(),res.end());
            ans.push_back(res);     
            return ;
        }
        int i = index;
        while(i<can.size()){
            if(can[i]<=target){
                res.push_back(can[i]);
                findComb(can,target-can[i],ans,res,i+1);
                res.pop_back();
                i++;
                if(i!=0 && i<can.size() && can[i]==can[i-1]){
                    while(i<can.size() && can[i]==can[i-1]) i++;
                }
               
            }else{
                return ;
            }
            }
            
        
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        findComb(candidates,target,ans,res,0);
        return ans;
    }
};