class Solution {
public:
   
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int sum = INT_MIN;
        while(start<end){
            int temp = min(height[start],height[end])*(end-start);
            if(temp>sum)
                sum = temp;
            if(height[start]>height[end]){
                end--;
            }else{
                start++;
            }
        }
        return sum;
    }
};