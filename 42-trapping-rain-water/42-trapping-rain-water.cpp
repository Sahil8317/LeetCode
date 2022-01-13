class Solution {
public:
    int trap(vector<int>& height) {
        
        int len = height.size();
        int low = 0,high = len-1;
        int lmax = 0,rmax=0;
        int res=0;
        while(low<=high){
            if(height[low]<=height[high]){
                if(height[low]>=lmax) lmax = height[low];
                else {
                    res+=lmax - height[low];
                }
                low++;
            }else{
                if(height[high]>=rmax) rmax = height[high];
                else{
                    res+=rmax-height[high];
                }
                high--;
            }
        }
        return res;

    }
};