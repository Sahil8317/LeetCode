class Solution {
public:
    
    void dfs(bool &res,int s,vector<int> adj[],vector<int> &vis){
        res = true;
        if(!vis[s]){
            vis[s] = 1;
            for(auto &i:adj[s]){
                if(!vis[i])
                  dfs(res,i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        vector<int> adj[n];
        int index = 0;
        for(auto &i:isConnected){
           for(int j=0;j<n;j++){
               if(index!=j && i[j]==1){
                   adj[index].push_back(j);
               }
           }
            index++;
        }
        int res = 0;
        for(int i=0;i<n;i++){
           bool ans = false;
            if(!vis[i])
              dfs(ans,i,adj,vis);
            if(ans)res++;
        }
        return res;
    }
};