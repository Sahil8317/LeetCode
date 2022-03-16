class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int first = popped[0];
        stack<int> stk;
        map<int,int> m;
        int index= 0 ;
        int i = 0;
       do{
           stk.push(pushed[i]);
           m[pushed[i]] = 1;
       }while(pushed[i++]!=first);
        index+=i;
        i = 0;
        while(i<popped.size()){
            if( !stk.empty() && popped[i]==stk.top()){ 
                stk.pop();
                i++;
            }else if(!m[popped[i]]) {
                int first = popped[i];
                do{
                   if(!m[pushed[index]]){
                        stk.push(pushed[index]);
                        m[pushed[index]] = 1;
                    } 
                }
                while(pushed[index++]!=first);
            }else{
               return false; 
            }
      }
        return true;
        
    }
};