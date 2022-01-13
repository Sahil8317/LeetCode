class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int gmax= 0;
        int cmax = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                cmax++;
            else{
                gmax = max(cmax,gmax);
                cmax = 0;
            }
        }
        return max(gmax,cmax);
    }
};