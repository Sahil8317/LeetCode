class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0] ;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      stack<int> stk,stk2;
        int ans = 0;
      sort(properties.begin(),properties.end(),cmp);
      for(auto vec : properties){
         if(stk.empty()){
             stk.push(vec[1]);
         } else{
             int ele = stk.top();
             if(ele<vec[1]){
                 while(!stk.empty() && stk.top()<vec[1]){
                     stk.pop();
                     ans++;
                 }
             }
           stk.push(vec[1]);
            
        }
     }
        return ans;
      
      
    }
};