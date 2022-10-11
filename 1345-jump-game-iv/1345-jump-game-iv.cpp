class Solution {
public:
    // DP WONT WORK AS IT CONTAINS A CYCLE so overlapping subproblems are different cant be memorized.
    
    int f(int index,vector<int> &arr,vector<int>dp,vector<int>visited){
        if(index==arr.size()-1) return 0;
        if(visited[index]!=-1) return 1000000;
        if(dp[index]!=-1)return dp[index];
        visited[index] = 1;
        int next = f(index+1,arr,dp,visited)+1;
        int prev = INT_MAX;
        if(index>0)
          prev = f(index-1,arr,dp,visited)+1;
        int ans = INT_MAX;
        for(int j = index+1;j<arr.size();j++){
            if(arr[j]==arr[index]){
                int third = f(j,arr,dp,visited)+1;
                ans = min(ans,third);
            }
        }
        return dp[index] = min(ans,min(next,prev));
    }
    
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> ele;
        vector<bool> visited(arr.size(),false);
        for(int i=0;i<arr.size();i++){
            ele[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int ans = 0;
        visited[0] = true;
        while(!q.empty()){
            for(int size = q.size()-1;size>=0;size-- ){
                int index = q.front();
                visited[index] = true;
                if(index==arr.size()-1) return ans;
                q.pop();
                vector<int> &next = ele[arr[index]];
                next.push_back(index-1);
                next.push_back(index+1);
                for(auto j : next){
                    if(j>=0 && j<arr.size() && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            ans++;
        }
        return ans;
    }
     
};