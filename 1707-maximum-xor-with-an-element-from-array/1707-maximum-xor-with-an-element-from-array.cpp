// Trie Question
class Node{
    public:
    Node * links[2];
    
    bool containsKey(int num){
        return (links[num]!=NULL);
    }
    
    Node * moveNext(int num){
    return links[num];
    }
    
    void putNode(int num,Node *node){
        links[num] = node;
    }
    
};

class Trie{
    private:
    Node * root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node *head = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i ) & 1;
            if(!head->containsKey(bit)){
               head->putNode(bit,new Node());
            }
            head = head->moveNext(bit);
        }
    }
    
    int getMaxXor(int num){
        Node * head = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(head->containsKey(1-bit)){
                maxNum = maxNum | (1 << i);
                head = head->moveNext(1-bit);
            }else{
                head = head->moveNext(bit);
            }
        }
        return maxNum;
    }
      
};
class Solution {
    
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
       vector<int> ans(queries.size(), 0); 
    vector<pair<int, pair<int,int>>> offlineQueries; 
    sort(arr.begin(), arr.end()); 
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
    sort(offlineQueries.begin(), offlineQueries.end()); 
    int i = 0; 
    int n = arr.size(); 
    Trie trie; 
    
    for(auto &it : offlineQueries) {
        while(i < n && arr[i] <= it.first) {
            trie.insert(arr[i]); 
            i++; 
        }
        if(i!=0) ans[it.second.second] = trie.getMaxXor(it.second.first); 
        else ans[it.second.second] = -1; 
    }
    return ans; 
        
    }
};