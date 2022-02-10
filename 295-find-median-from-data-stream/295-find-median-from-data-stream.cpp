class MedianFinder {
private:
priority_queue<int> first;
priority_queue<int,vector<int>,greater<int>> second;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
       if(first.empty() || first.top()>num)first.push(num);
       else second.push(num);
        if(first.size() > second.size() + 1){
            second.push(first.top());
            first.pop();
        }else if(second.size()>first.size()+1){
            first.push(second.top());
            second.pop();
        }
    }
    
    double findMedian() {
        if(first.size()==second.size())
            return (double) (first.top()+second.top())/2;
        else 
            if(first.size()>second.size())return first.top();
            else return second.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */