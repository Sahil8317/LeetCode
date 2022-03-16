class Solution {
public:
    int dfs(int s,vector<int> adj[],vector<int> &vis){
        vis[s] = 1;
        int changeEdge = 0;
        for(auto &i:adj[s]){
            if(!vis[abs(i)]){
               changeEdge+= dfs(abs(i),adj,vis)+(i>0); // i>0 means change the edge direction  
            }
        }
        return changeEdge;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
      vector<int> vis(n,0);
      vector<int> adj[n];
      for(auto &i:connections){
          adj[i[0]].push_back(i[1]);
          adj[i[1]].push_back(-i[0]); // marking negative to judge the edge is comming inwards 
      }
        int ans = dfs(0,adj,vis);
        return ans;
    }
};