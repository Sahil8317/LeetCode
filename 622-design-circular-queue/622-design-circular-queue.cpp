class MyCircularQueue {
private :
    int rear;
    int front;
    int *arr;
    int size;
    bool flag ;
public:
    MyCircularQueue(int k) {
        size = k;
        rear = 0;
        front = 0;
        arr = new int[size];
        flag = true;
    }
    
    bool enQueue(int value) {
        if(rear==front && !flag)
            return false;
        if(rear==front && flag) flag =false;
        arr[rear] = value;
        rear = (rear + 1)%size;
        return true;
    }
    
    bool deQueue() {
        if(rear == front && flag)
            return false;
        int x = arr[front];
        front = (front+1)%size;  
        if(front ==rear && !flag) flag = true;
        return true;
    }
    
    int Front() {
        if(rear==front && flag)
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear==front && flag)
            return -1;
        return arr[(rear + size -1) % size] ;
    }
    
    bool isEmpty() {
        if(rear==front && flag)
            return true;
        return false;
    }
    
    bool isFull() {
        if(rear ==front && !flag)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */