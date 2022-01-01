class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int largest = nums[0];
      int clargest = nums[0];
        for(int i=1;i<nums.size();i++){
           clargest = max(clargest+nums[i],nums[i]);
            largest = max(clargest,largest);
        }
        return largest;
    }
   
};