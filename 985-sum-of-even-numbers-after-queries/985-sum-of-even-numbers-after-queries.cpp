class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                sum+=nums[i];
            
        }
         
        //1. if prev nums[index] is even then remove it after also its even then again add it
        //2. if prev nums[index] is even and after it becomes odd then you already removed it
        //3. if prev nums[index] is odd then it becomes even then just add that to sum
        //4. if prev nums[index] is odd and after also its odd only then no effect on sum  
        for(auto vec:queries){
          int index = vec[1];
          int val = vec[0];
          if(nums[index]%2==0){
              sum -=nums[index];
          }
          nums[index]+=val;
          if(nums[index]%2==0){
              sum+=nums[index];
          }
            ans.push_back(sum);
        }
        if(ans.empty()) ans.push_back(0);
        return ans ;
    }
};