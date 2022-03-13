class Solution {
public:

    bool dfs(string startNode,string goalNode,map<string,vector<pair<string,double>>> adj,map<string,int> vis,map<string,int>&present,double cost,double &ans){
        if(present[startNode]==0 || present[goalNode]==0){
            ans = -1.0;
            return true;
        }
        if(vis[startNode]==0){
            if(startNode==goalNode) {
                ans = 1.0;
                return true;
            }
           
            vis[startNode]= 1;
            
            for(auto &edges:adj[startNode]){
                double prev =cost;
                if(vis[edges.first]==0){
                cost = cost*edges.second;
                if(edges.first==goalNode){
                   // cout<<cost<<endl;
                   ans = cost;
                   return true ;
                }
               bool f =  dfs(edges.first,goalNode,adj,vis,present,cost,ans);
                if(!f){ 
                    cost = prev;
                }
                else return true;
                }
            }
        }else{
            cost = 1.0;
        }
        return false ;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> present;
        for(auto &i:equations){
           present[i[0]] = 1;
           present[i[1]] = 1;
        }
        map<string,int> vis;
        map<string,vector<pair<string,double>>> adj;
        int j = 0;
        for(auto i:equations){
            adj[i[0]].push_back({i[1],values[j]});
            adj[i[1]].push_back({i[0],(1/values[j])});
            j++;
        }
        vector<double> ans;
        double cost = 1.0;
        for(auto query:queries){
          double res = -1.0;
         dfs(query[0],query[1],adj,vis,present,1.0,res);
         ans.push_back(res);
        }
        return ans;
    }
};