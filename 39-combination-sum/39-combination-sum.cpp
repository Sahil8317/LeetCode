class Solution {
public:

    void findCom(vector<int> &can,int target,vector<vector<int>> &ans,vector<int> &res,int index){
        if(target==0){
            ans.push_back(res);
            return ;
        }
        for(int i=index;i<can.size();i++){
            if(can[i]<=target){
                res.push_back(can[i]);
                findCom(can,target-can[i],ans,res,i);
                res.pop_back();
            }else{
                return ;
            }
        }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        findCom(candidates,target,ans,res,0);
        return ans;
    }
};