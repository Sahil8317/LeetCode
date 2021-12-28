class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
           if(nums[i]==0){
               int k = i;
               for(int j=i;j<n;j++){
                   if(nums[j]!=0){
                       k = j;
                       break;
                    }
               }
               int t = nums[i];
               nums[i] = nums[k];
               nums[k] = t;
           }
            
        }
    }
};