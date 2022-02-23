class Solution {
public:
    bool dfsCycle(int node,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[]){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto &it:adj[node]){
          if(vis[it]==0){
             if(dfsCycle(it,vis,dfsVis,adj)) return true;
          }else if(dfsVis[it]==1) return true;
        }
        dfsVis[node] = 0;
        return false;
    }
    

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> vis(numCourses,0),dfsVis(numCourses,0);
        vector<int> adj[numCourses];
        for(auto &it:pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCycle(i,vis,dfsVis,adj)) return false;
            }
        }
        return true;
    }
};