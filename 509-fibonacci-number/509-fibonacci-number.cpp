class Solution {
public:
    
    int f(int n){
        if(n==0 || n==1) return n;
        int num = f(n-1)+f(n-2);
        return num;
    }
    int fib(int n) {
      return f(n);  
    }
};