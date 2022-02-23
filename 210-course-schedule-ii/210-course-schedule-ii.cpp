class Solution {
public:
    
    bool topoDFS(int node,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[],stack<int> &ans){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(topoDFS(it,vis,dfsVis,adj,ans)) return true;
            }else if(dfsVis[it]==1){
                return true;
            }
        }  
        dfsVis[node] = 0;
        ans.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0),dfsVis(numCourses,0);
        vector<int> ans;
        stack<int> res;
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
              if(topoDFS(i,vis,dfsVis,adj,res)) return ans;
        }
        while(!res.empty()){
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};