class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int> ans({-1,-1});
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                int right = mid;
                int left =mid;
                while(left>=0 && nums[left]==target)
                    left--;
                ans[0] = left+1;
                ans[1] = mid;
                while(right < nums.size() && nums[right]==target)
                    right++;
                ans[1] = right-1; 
                return ans;
            }else if (nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};