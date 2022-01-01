class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //find the break point
        int index = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
            
        }
        // if found swap it with the element next greater to it
        if(index!=-1){
            for(int i=n-1;i>=0;i--){
                if(nums[index]<nums[i]){
                    int t = nums[index];
                    nums[index] = nums[i];
                    nums[i] = t;
                    break;
                }
            }
        }
        // reverse all elements after the break point
        int i = index+1,j = n-1;
        while(i<=j){
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }
    }
};