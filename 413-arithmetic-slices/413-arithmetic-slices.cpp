class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 3;i<=n;i++){     // for windows of diff size
        int left = 0,right = i-1;
        while(right<n){             // for each window of size i
           int j = left,prev = INT_MIN;
            bool check = true;
            vector<int> res;
            while(j<right){         // checking a particular window of i
                int diff = (nums[j]-nums[j+1]);
                // res.push_back(nums[j]);
                // res.push_back(nums[j+1]);
                if(prev==INT_MIN){
                    prev = diff;
                }else{
                    if(prev!=diff){
                        check = false;
                        //res.clear();
                        break;
                    }
                }
                j++;
            } 
            if(check){
               ans++;
               //  cout<<res.size()<<endl;
               // for(auto it:res) cout<<it<<endl;
            } 
            left++;
            right++;
        }
      }
        return ans;
    }
};