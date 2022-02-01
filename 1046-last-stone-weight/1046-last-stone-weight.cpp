class Solution {
public:
    // priority queue question asked in publicis sapients
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(stones.empty())
            return 0;
        if(stones.size()==1) return stones[0];
       priority_queue<int> queue(begin(stones), end(stones));
        while(queue.size()>1){
            int first = queue.top();
            queue.pop();
            int second = queue.top();
            queue.pop();
            if(first>second) queue.push(first-second);
        }
        if(queue.empty())
            return 0;
        return queue.top();
        
    }
};