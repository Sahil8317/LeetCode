class Node{
public:
    Node *links[2];
    
    bool containsKey(int num){
        return (links[num]!=NULL);
    }
    
    Node * moveNext(int num){
        return links[num];
    }
    
    void insertNode(int num,Node* n){
        links[num] = n;
    }
    
    
    
};

class Trie{
    private :
     Node * root;
    public:
    Trie(){
        root = new Node();
    }
   
    void insert(int num){
        Node *head = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;   // producing each bit
            if(!head->containsKey(bit)){
                head->insertNode(bit,new Node());
            }
            head = head->moveNext(bit);
            
        }
    }
    
    int getMax(int num){
        Node *head = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(head->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                head= head->moveNext(1-bit);
            }else{
              head = head->moveNext(bit);  
            }
        }
        return maxNum;
    }
  
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it :nums){
            trie.insert(it);
        }
        int ans = 0;
      
            for(int j =0;j<nums.size();j++){
                int res = trie.getMax(nums[j]);
                ans = max(res,ans);
            }
        
        return ans;
    }
};