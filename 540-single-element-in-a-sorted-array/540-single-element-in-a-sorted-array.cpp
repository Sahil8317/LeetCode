class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int low = 0,high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            int left = mid-low;
            int right = high-mid;
            if(high==low)
                return nums[low];
            if(nums[mid-1]==nums[mid]){
                left = left-1;
            }
            else if(nums[mid+1]==nums[mid]){
                right = right-1;
            }else{
                return nums[mid];
            }
            
            if(left%2 == 1){
                high = low+left-1 ;
            }
            if(right%2 == 1){
                low = high-right+1;
            }
        }
        return -1;
        
    }
};