// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<int> parent(V,-1);
        vector<bool> mstSet(V,false);
        vector<pair<int,int>> adjList[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjList[i].push_back({it[0],it[1]});
            }
        }
        
        key[0] = 0;
        parent[0] = -1;
        for(int i = 0;i<V-1;i++){
            int mmin = INT_MAX,node = 0;
            for(int j=0;j<key.size();j++){
                if(mstSet[j]==false && key[j]<mmin){
                    mmin = key[j];
                    node = j;
                }
            }
            mstSet[node] = true;
            for(auto it:adjList[node]){
                int nextNode = it.first;
                int nextWt = it.second;
                if(mstSet[nextNode]==false && nextWt<key[nextNode]){
                    key[nextNode] = nextWt;
                    parent[nextNode] = node;
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<parent.size();i++){
            ans+=key[i];
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends