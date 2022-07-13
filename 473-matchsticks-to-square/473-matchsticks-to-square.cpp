class Solution {
public:
    // a problem to find 4 subsets of equal sum
    bool backtrack(vector<int> &visited,vector<int>&arr,int index,int curr,int target,int k){
        if(k==1)
            return true;
        if(curr==target){
           return backtrack(visited,arr,0,0,target,k-1);
        }
        
        for(int j= index;j<arr.size();j++){
            if(visited[j] || curr+arr[j]>target) continue;
            visited[j] = true;
            if(backtrack(visited,arr,j+1,curr+arr[j],target,k))
                return true;
            visited[j] = false;
        }
        return false;
    }
    
    bool makesquare(vector<int>& arr) {
       int n = arr.size();
       if(n==4){
           for(int i=0;i<n-1;i++){
               if(arr[i]!=arr[i+1])
                   return false;
           }
         return true;
       }else{
           int sum = 0;
           for(int i=0;i<n;i++){
               sum+=arr[i];
           }
           int target = sum/4;
           int temp = sum%4;
           if(temp!=0) return false;
           sort(arr.begin(),arr.end(),greater<int>());
           for(int i=0;i<n;i++){
               if(arr[i]>target) return false;
           }
           vector<int> visited(arr.size(),false);
           return backtrack(visited,arr,0,0,target,4);

       }
    }
};