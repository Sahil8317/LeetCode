class Solution {
public:
    
    void dfs(int s,int g,vector<vector<int>> &adj,vector<int> path,vector<vector<int>> &ans){
         path.push_back(s);
        if(s==g){
           ans.push_back(path);
            return ;
        }
        for(auto &i:adj[s]){
            dfs(i,g,adj,path,ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        int s = 0;
        dfs(s,graph.size()-1,graph,path,ans);
        return ans;
    }
};