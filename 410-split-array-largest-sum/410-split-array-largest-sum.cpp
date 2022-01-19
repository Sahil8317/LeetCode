class Solution {
public:
    
    
    bool isSubsetPossible(int barrier,int m,vector<int> &nums){
    int subsetSum = 0,subsetCount = 1,n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>barrier)
                return false;
            if(nums[i]+subsetSum > barrier){
                subsetCount++;
                subsetSum = nums[i];
            }else{
                subsetSum+=nums[i];
            }
            
        }
        
        if(subsetCount<=m)
            return true;
        
        return false;
    
    }
    int splitArray(vector<int>& nums, int m) {
        if(m>nums.size())
            return -1;
        int low = nums[0];
        int high = 0;
        for(int i=0;i<nums.size();i++){
            high +=nums[i];
            low = min(low,nums[i]);
        }
        int ans = -1;
        while(low<=high){
            int mid = low+high >> 1;
            if(isSubsetPossible(mid,m,nums)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};