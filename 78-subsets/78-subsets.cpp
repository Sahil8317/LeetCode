class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int numbers = (1<<n);   // 2 power n
        for(int i=0;i<numbers;i++){
            vector<int> res;
            for(int j=0;j<nums.size();j++){
                if((i & (1<<j))){
                    res.push_back(nums[j]);
                }
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};