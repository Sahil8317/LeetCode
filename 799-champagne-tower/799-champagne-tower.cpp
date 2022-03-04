class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       map<pair<double,double>,double> dp;
        dp[{0,0}] = poured;
       for(int row= 1;row<=query_row;row++){ 
           for(int glass = 0;glass<row+1;glass++){  // each row will have row+1 glasses
                 double x = ((dp[{row-1,glass-1}]-1)/2);
                 double y = ((dp[{row-1,glass}]-1)/2);
                 if(x<0) x = 0;
                 if(y<0) y = 0;
               dp[{row,glass}] = x+y;  //pascal traingle   
               if(row==query_row && glass==query_glass)
                   return min(dp[{row,glass}],1.0);
               
             }
         }
        return min(1.0,dp[{0,0}]);
    }
};