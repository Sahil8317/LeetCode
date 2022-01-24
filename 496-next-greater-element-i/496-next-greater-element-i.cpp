class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int> stk;
        map<int,int> m;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!stk.empty() && nums2[i]>=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                m[nums2[i]] = -1;
            }else{
                m[nums2[i]] = stk.top();   
            }
            stk.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};