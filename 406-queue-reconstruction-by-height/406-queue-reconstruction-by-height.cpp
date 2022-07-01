class Solution {
public:
   static bool sortvector(vector<int> &p1,vector<int> &p2){
        if(p1[0]>p2[0])return true;
        else if(p1[0]==p2[0]){
            return p1[1]<p2[1];
        }else{
            return false;
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size(),vector<int>(2,-1));
        sort(people.begin(),people.end(),sortvector);
        // which data structure to use?
         for(int i=0;i<people.size();i++){
             vector<int>ele = people[i];
           if(ans[ele[1]][0]==-1){
               ans[ele[1]] = ele;
           }else{
               int j = ele[1];
               int index = i-1;
               while(index>=0 && index>=j){
                   ans[index+1] = ans[index];
                   index--;
               }
               ans[ele[1]] = ele;
           }
         }
        return ans;
    }
};