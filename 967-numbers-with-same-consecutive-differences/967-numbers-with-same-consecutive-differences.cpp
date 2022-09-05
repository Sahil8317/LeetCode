class Solution {
public:
    
    void selectNumber(int &number,int prev,int k,int digit,int n,vector<int> &t){
        if(digit>n) return ;
        int newNumber = -1;
        newNumber = prev-k;
        if(newNumber>=0){
            int temp = number+newNumber*pow(10,(n-digit));
            selectNumber(temp,newNumber,k,digit+1,n,t); 
            if(digit==n)
                t.push_back(temp);
        }
        if(k!=0){
        newNumber = prev+k;
        if(newNumber>=0 && newNumber<10){
            int temp = number+newNumber*pow(10,(n-digit));
            selectNumber(temp,newNumber,k,digit+1,n,t);  
            if(digit==n)
                t.push_back(temp);
        }
            
      }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        int number = -1;
        for(int i=1;i<=9;i++){
            int t = i*pow(10,(n-1));
          selectNumber(t,i,k,2,n,ans);
        }
        return ans;
    }
};