class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        int first = 0;
        int n = nums.size();
        int last  = n-1;
        while(nums[first]>nums[last]){
            last--;
        }
        int low = first;
        int high = last;
        while(low<=high){
            int mid  = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        low = last+1;
        high = n-1;
        while(low<=high){
            int mid  = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};