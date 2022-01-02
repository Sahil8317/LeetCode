class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0,count2=0,num1=INT_MIN,num2=INT_MIN;
        for(int i:nums){
            if(i==num1)
                count1++;
            else if(i==num2)
                count2++;
            else if(count1==0){
                num1 = i;
                count1= 1;
            }else if(count2==0){
                num2 = i;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1=0;
        count2=0;
       for(int i:nums){
           if(i==num1)
               count1++;
           if(i==num2)
               count2++;
       }
        if(count1>n/3)
            ans.push_back(num1);
        if(count2>n/3)
            ans.push_back(num2);
        
        
        return ans;
    }
};