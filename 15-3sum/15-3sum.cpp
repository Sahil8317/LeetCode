class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> ans;
        int a=0,low=0,high = len-1;
        for(int i=0;i<len-2;i++){
            if(i==0 || nums[i-1]!=nums[i]){
            a = -nums[i];
            low = i+1;
            high = len-1;
            while(low<high){
                if(nums[low]+nums[high]==a){
                    vector<int> t;
                    t.push_back(-a);
                    t.push_back(nums[low]);
                    t.push_back(nums[high]);
                    while(low<high && nums[low]==nums[low+1] )
                        low++;
                    
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    
                    sort(t.begin(),t.end());
                    ans.push_back(t);
                    
                }
                if(nums[low]+nums[high]<a){
                    low++;
                }else{
                    high--;
                }
            }
        }
            
}
        return ans;
    }
};