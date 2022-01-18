class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int i = 0;
        int j = 0;
        int n = nums1.size(),m = nums2.size();
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }else{
                num.push_back(nums2[j]);
                    j++;
            }
        }
        if(i<n){
            for(;i<n;i++){
                num.push_back(nums1[i]);
            }
        }
        if(j<m){
            for(;j<m;j++){
                num.push_back(nums2[j]);
            }
        }
        int low =0;
        int high = num.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(num.size()%2==0){
            double median = (double)(num[mid]+num[mid+1]) /2.0;
            return median;
            }else{
               return (double) num[mid];  
            }
        }
        return 1.0;
    }
};