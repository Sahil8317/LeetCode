class Solution {
public:
    
    int f(int index,int n,vector<int> &arr){
        if(index==0){
            return 1;
        }
        int notTake = 1*f(index-1,n,arr);
        int take = INT_MIN;
        if(arr[index]<=n){
            take = f(index,n-arr[index],arr)*arr[index];
        }
        return max(take,notTake);
    }
    int integerBreak(int n) {
        vector<int> arr;
        for(int i=1;i<n;i++)
            arr.push_back(i);
        
        return f(n-2,n,arr);
    }
};