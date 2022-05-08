class Solution {
public:
    
    int f(int index,vector<int> &nums,int target){
        if(index==0){
            return (target+nums[index]==0)+(target-nums[index]==0);  // in some of the test case taking the index element in both the cases will give you the answer.
        }
        int notTake = f(index-1,nums,target+nums[index]);
        int take = f(index-1,nums,target-nums[index]);
        
        return notTake+take;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums.size()-1,nums,target);
    }
};