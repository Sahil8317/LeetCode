class Solution {
public:
    
    bool f(int index,vector<int>& arr,vector<int> &visited){
        if(visited[index]!=-1) return false;
        if(arr[index]==0) return true;
        
        
        bool takePrev = false,takeNext = false;
        visited[index] = 1;
        if(index-arr[index]>=0){
            takePrev = f(index-arr[index],arr,visited);
            //visited[index-arr[index]] = 1;
        }
        if(index+arr[index]<arr.size()){
            takeNext = f(index+arr[index],arr,visited);
           // visited[index+arr[index]] = 1;
        }
        
       
        return takePrev || takeNext;
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),-1);
        return f(start,arr,visited);
    }
};