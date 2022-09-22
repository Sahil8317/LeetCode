class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                if(!nums.empty())
                    nums.pop_back();
            }else if(ops[i]=="D"){
                if(!nums.empty())
                nums.push_back(nums[nums.size()-1]*2);
            }else if(ops[i]=="+"){
                if(!nums.empty()){
                int prev1 = nums[nums.size()-1];
                int prev2 = nums[nums.size()-2];
                nums.push_back(prev1+prev2);                
                }
            }else{
              nums.push_back(stoi(ops[i]));  
            }
        }
        int ans =0;
        for(auto i:nums){
            ans+=i;
        }
        return ans;
    }
};