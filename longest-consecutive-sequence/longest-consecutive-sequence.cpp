class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count=0;
        int gcount=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
            if(nums[i]-nums[i-1]==1 ){
                count+=1;
            }else{
                if(count+1>gcount)
                    gcount =count+1;
                count=0;
            }
        }
        }
        if(count+1>gcount)
           return count+1;
        else
            return gcount;
    }
};