class Solution {
    bool cmp(vector<int> &v,vector<int> &v1){
            return v[0]<v1[0];
    }
    
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        pair<int,int> p ;
        p.first = intervals[0][0];
        p.second = intervals[0][1];
        int i =0;
        while(i<n){
            if(intervals[i][0]-p.second <=0){
                p.second = max(intervals[i][1],p.second);
                
            } else{
                vector<int> v;
                v.push_back(p.first);
                v.push_back(p.second);
                ans.push_back(v);
                p.first = intervals[i][0];
                p.second = intervals[i][1];
                
            }
            i++;
        }
             vector<int> v;
                v.push_back(p.first);
                v.push_back(p.second);
                ans.push_back(v);
        
        return ans;
        
    }
};