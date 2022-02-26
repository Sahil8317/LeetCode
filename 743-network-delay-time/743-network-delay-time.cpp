class Solution {
public:
    // normal topo sort + BFS solution will not work becoz there may exists a cycle in graph

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
        int node = pq.top().second;
        int nodeDist = pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
          int nextNode = it.first;
          int nextDist = it.second;
          if(nextDist+nodeDist<dist[nextNode]){
              dist[nextNode] = nextDist+nodeDist;
              pq.push({dist[nextNode],nextNode});
          }
        }
    }
        int ans = 0;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};