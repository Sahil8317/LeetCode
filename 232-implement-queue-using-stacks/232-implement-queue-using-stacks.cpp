class MyQueue {
    stack<int> input;
    stack<int> output;
        
public:
    MyQueue() {
        
    }
    
    void push(int x) {
     input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int n = output.top();
            output.pop();
            return n;
        }else{
            int s = input.size();
            for(int i=0;i<s;i++){
                output.push(input.top());
                input.pop();
            }
            int n = output.top();
            output.pop();
            return n;
        }
    }
    
    int peek() {
       if(!output.empty()){
            return output.top();
        }else{
            int s = input.size();
            for(int i=0;i<s;i++){
                output.push(input.top());
                input.pop();
            }
            int n = output.top();
            return n;
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */