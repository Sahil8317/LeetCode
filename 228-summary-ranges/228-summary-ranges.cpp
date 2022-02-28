class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string> ans;
        if(nums.empty()) return ans; 
        long long first = 0,last = 0;
        long long i = 0;
        for(;i<nums.size()-1;i++){
                first = nums[i];
                long long diff = abs(abs(nums[i+1])-abs(nums[i]));
                while( i< nums.size()-1 && diff==1){
                    i++;
                    if(i<nums.size()-1)
                    diff = abs(abs(nums[i+1])-abs(nums[i]));
                }
                last = nums[i];
                if(first==last) ans.push_back(to_string(first));
                else{
                    ans.push_back(to_string(first)+"->"+to_string(last));
                }
        }
        if(i!=nums.size()) ans.push_back(to_string(nums[nums.size()-1]));
        return ans;
    }
};