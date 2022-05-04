class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans =0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=k && m[nums[i]]){
            m[nums[i]]--;
            if(m[k-nums[i]]){
                ans++;
                m[k-nums[i]]--;
            }
          }
        }
        return ans;
    }
};