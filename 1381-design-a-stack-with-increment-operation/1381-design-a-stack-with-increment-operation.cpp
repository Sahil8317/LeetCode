class CustomStack {
private :
    int size;
    int top;
    int * arr;
public:
    CustomStack(int maxSize) {
        size = maxSize;
        arr = new int [size];
        top = -1;
    }
    void push(int x) {
     if(top==size-1){
         return ;
     }
        top++;
        arr[top] = x;
        
    }
    
    int pop() {
        if(top==-1)
            return -1;
        int x = arr[top];
        top--;
        return x;
    }
    
    void increment(int k, int val) {
        int i = 0;
        if(k<=top){
            while(i<k){
                arr[i]+=val;
                i++;
            }
        }else{
            while(i<=top){
            arr[i]+=val;
            i++;
        }
     
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */