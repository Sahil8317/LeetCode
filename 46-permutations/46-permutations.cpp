class Solution {
public:
    void nextPerm(vector<int> &nums,vector<vector<int>> &ans,vector<int> &res){
       if(nums.size()==0){
           ans.push_back(res);
           return ;
        }
        for(int i=0;i<nums.size();i++){
            res.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            nextPerm(nums,ans,res);
            nums.insert(nums.begin()+i,res.back());
            res.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        nextPerm(nums,ans,res);
        return ans;
        
    }
};