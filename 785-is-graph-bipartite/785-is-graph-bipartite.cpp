class Solution {
public:
    // using BFS
    // taking 2 colors 0  and 1
    bool checkIfBipartite(int s,vector<vector<int>> adj,int color[]){
       queue<int> q;
        q.push(s);
        color[s] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto j:adj[node]){
                if(color[j]==-1){
                    color[j] = 1-color[node];  // color in opposite way
                    q.push(j);
                }else if(color[j]==color[node])  //two adjacent nodes have same color  not a bipartite
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       int color[n];
       memset(color,-1,sizeof color);
       for(int i=0;i<n;i++){
           if(color[i]==-1){
              bool ans = checkIfBipartite(i,graph,color);
               if(!ans) return false;   // if any component is not bipartite then the whole graph is not bipartite
           }
       } 
        return true;
    }
};