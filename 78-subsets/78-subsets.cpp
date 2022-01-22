class Solution {
public:
    
    void rFun(vector<int> &nums,vector<vector<int>> &ans,int index,vector<int> res){
        ans.push_back(res);
        for(int i=index;i<nums.size();i++){
            res.push_back(nums[i]);
            rFun(nums,ans,i+1,res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        rFun(nums,ans,0,res);
        return ans;
    }
};