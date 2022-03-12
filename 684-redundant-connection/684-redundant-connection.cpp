class DSU{
    public:
    vector<int> rank;
    vector<int> parent;
    
    DSU(int nodes){
        rank = vector<int>(nodes+1,0);
        parent = vector<int>(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            parent[i] = i;
        }
    }
  
    int getParent(int node){
        if(parent[node]==node) return node;
        else return getParent(parent[node]);
    }
    
    void unionNodes(int u,int v){
        parent[u] =v;
    }
};

class Solution {
public:
   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU d = DSU(edges.size());
        vector<vector<int>> ans;
       for(int i=0;i<edges.size();i++){
           if(d.getParent(edges[i][0])==d.getParent(edges[i][1])){
               vector<int> ans = {edges[i][0],edges[i][1]};
               return ans;
           }else{
             d.unionNodes(d.getParent(edges[i][0]),d.getParent(edges[i][1]));
           }
           
       }
        return {};
    }
};