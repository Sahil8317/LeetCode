class Solution {
public:
    
    
    // for a traingle to form the sum of two sides of the traingle should be less than the sum of remaining two sides.
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]<nums[i+1]+nums[i+2]) ans =max(ans,nums[i]+nums[i+1]+nums[i+2]);
        }
        return ans;
    }
};