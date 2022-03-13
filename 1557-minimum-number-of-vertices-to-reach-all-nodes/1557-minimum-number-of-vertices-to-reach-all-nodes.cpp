class DSU{
    public:
    vector<int> parent;
    DSU(int n){
        parent = vector<int>(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    
    int getParent(int node){
        if(parent[node]==node) return node;
        return getParent(parent[node]);
    }
    
    void unionNodes(int u,int v){
        parent[v] = u;
    }
};

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       set<int> s;
        DSU d = DSU(n);
       for(auto i:edges){
         d.unionNodes(i[0],i[1]); 
      }
        for(int i=0;i<n;i++){
          s.insert(d.getParent(i));  
        }
        vector<int> ans;
        for(auto &i:s){
            ans.push_back(i);
        }
        return ans;
    }
};