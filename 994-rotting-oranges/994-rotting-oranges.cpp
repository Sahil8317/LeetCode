class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int rottenOrange = 0;
        int countOrange = 0;
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   q.push({i,j});  
                }
                if(grid[i][j]!=0){
                    countOrange+=1;
                }
            }
        }
        int ans = 0;  
        // BFS
        while(!q.empty()){
            int k = q.size();
            rottenOrange+=k;
            while(k--){
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            // left
            if(j-1 >=0 && grid[i][j-1]==1){
                grid[i][j-1] = 2;
                q.push({i,j-1});
                
            }
            // right
            if(j+1 <m && grid[i][j+1]==1){
                grid[i][j+1] = 2;
                q.push({i,j+1});
                 

            }
            // top
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j] = 2;
                q.push({i-1,j});
                
            }
            // bottom 
            if(i+1 <n && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
                
            }
        }
            if(!q.empty()) ans++;
           
        }
        if(rottenOrange==countOrange)
            return ans;
        return -1;
    }
};