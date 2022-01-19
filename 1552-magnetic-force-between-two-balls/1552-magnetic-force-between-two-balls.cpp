class Solution {
public:
    // same as agreesive cows
    bool isPossible(int mid,vector<int>&nums,int m){
        int count = 1;
        int position = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-position >= mid){
                count++;
                position = nums[i];
            }
            if(count==m)
                return true;
        }
        
        return false;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int n = position.size();
        int high = position[n-1]-position[0];
        int ans = -1;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(isPossible(mid,position,m)){
                ans = mid;
                low= mid +1;
            }else{
                high = mid-1;
            }
    }
        return ans;
        
    }
};