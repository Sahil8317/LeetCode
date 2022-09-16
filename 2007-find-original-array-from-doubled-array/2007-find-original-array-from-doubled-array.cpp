class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
         vector<int> ans;
        sort(changed.begin(),changed.end());
        if(changed.size()%2!=0) return ans;      
        map<int,int> presence;
       for(int i:changed){
           presence[i]+=1;
       }
        for(int i=0;i<changed.size();i++){
            if(presence[changed[i]]!=0){
                int num = changed[i];
                num=num*2;
                presence[changed[i]]--;
                if(presence[num]!=0 ){
                    ans.push_back(changed[i]);
                    presence[num]--;
               }
        }
     }
        if(ans.size()*2==changed.size())
        return ans;
        return {};
    }
};