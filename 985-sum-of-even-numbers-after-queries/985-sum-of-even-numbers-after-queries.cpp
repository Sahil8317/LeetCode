class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> m;
        int sum =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                m[i] = nums[i];
                sum+=nums[i];
            }
        }
        for(auto vec:queries){
           int val = vec[0];
           int index = vec[1];
           nums[index] = nums[index]+val;
           if(nums[index]%2==0){
               if(m.find(index)!=m.end()){
                   // means that number already exits before now you have to take its diff.
                   int diff = nums[index]- m[index];
                   sum+=diff;
               }else{
                   sum+=nums[index];
               }
                m[index] = nums[index];
           }else{
               if(m.find(index)!=m.end()){
                  sum = sum-m[index];
                   m.erase(index) ;
               }
           }
             ans.push_back(sum);
        }
        if(ans.empty()) ans.push_back(0);
        return ans ;
    }
};