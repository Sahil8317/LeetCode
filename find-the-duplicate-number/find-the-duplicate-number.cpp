class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int last = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==last)
                return last;
            last = nums[i];
        }
        return 0;
    }
};


