class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dist(n,INT_MIN);
        priority_queue<pair<double,int>> pq;
        dist[start] = 0;
        pq.push({1.0,start});
        vector<pair<int,double>> adj[n];
        int k = 0;
        for(auto it:edges){
           adj[it[0]].push_back({it[1],succProb[k]});
           adj[it[1]].push_back({it[0],succProb[k++]});   
        }
        while(!pq.empty()){
            int node = pq.top().second;
            double nodeDist = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int nextNode = it.first;
                double nextDist = it.second;
                if(nextDist*nodeDist>dist[nextNode]){
                    dist[nextNode] = nodeDist*nextDist;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        if(dist[end]==INT_MIN) return 0.0;
        return dist[end];
    }
};