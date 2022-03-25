class Solution {
public:
    static bool cmp(vector<int> &p1,vector<int> &p2){
        int diff1 = abs(p1[0]-p1[1]);
        int diff2 = abs(p2[0]-p2[1]);
        if(diff1>diff2) return true;
        return false;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int sumA = 0,sumB = 0;
        int countA = 0,countB = 0;
        int n = costs.size()/2;
        for(auto cost:costs){
           if(cost[0]<cost[1]){
               if(countA!=n){
               sumA+=cost[0];
               countA++;
               }else{
                  sumB+=cost[1];
                   countB++;
               }
           }else{
               if(countB!=n){
                   sumB+=cost[1];
                   countB++;
               }else{
                   sumA+=cost[0];
                   countA++;
               }
           }
        }
        return sumA+sumB;
    }
};