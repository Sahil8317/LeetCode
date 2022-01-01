class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1)
            return ;
        int n = 0;
        map<int,int> m;
        for(int i:nums){
            m[i]+=1;
            if(i>n)
                n = i;
      }
        nums.clear();
        for(int i=0;i<=n;i++){
            int ind = m[i];
            while(ind>0){
            nums.push_back(i);
                ind--;
        }
        }
    }
};