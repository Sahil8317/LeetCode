class Solution {
public:
    void DFS(int s,vector<vector<int>> &rooms,vector<int> &vis){
        if(!vis[s]){
            vis[s] = 1;
            for(auto &i:rooms[s]){
                if(!vis[i])
                  DFS(i,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        DFS(0,rooms,vis);
        bool ans = true;
        
        for(auto &i:vis){
            if(i==0){
                ans = false;
                return ans;
            }
        }
        return ans;
    }
};