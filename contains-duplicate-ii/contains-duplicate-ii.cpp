class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      map<int,int> m;
      map<int,vector<int>> m2;
        for(int i=0;i<nums.size();i++){
           m[nums[i]]+=1;
            m2[nums[i]].push_back(i);   
    }
        for(auto i:m2){
            if(i.second.size()>=2){
                vector<int> v  = i.second;
                int n = v.size();
                for(int j=0;j<n;j++){
                    int m = v[j];
                    for(int l = j+1;l<n;l++){
                        if(abs(m-v[l])<=k)
                            return true;
                    }
              }
            }
}
        return false;
        
        
    }
};