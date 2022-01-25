class Node{
public:
    int key;
    int val;
    int freq;
    Node *prev;
    Node *next;
    
    Node(int k,int v,int f){
        key = k;
        val = v;
        freq = f;
    }
};

class LFUCache {
private:
    int cap;
    map<int,pair<Node*,Node*>>freq;
    map<int,Node*> m;
    int minFreq;
        
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 1;
    }
    bool empty(pair<Node*,Node*>p){
      Node *head = p.first;
      Node *tail = p.second;
        if(head->next == tail && tail->prev==head)
            return true;
        return false;
    }
   
    
    Node *insertNode(int k,int v,int f){
        Node *newNode = new Node(k,v,f);
        if(freq[f].first==NULL){
        Node* head = new Node(-1,-1,-1);
        Node *tail = new Node(-1,-1,-1);
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;
        freq[f] = {head,tail};
        }
        Node *head = freq[f].first;
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        if(f<minFreq){
            minFreq = f;
        }
        return newNode;
    }
    
    void deleteNode(Node *del){
        del->prev->next = del->next;
        del->next->prev = del->prev;
        if(empty(freq[minFreq])){
            minFreq+=1;
        }
        
    }
    
    int get(int key) {
        if(cap<=0){
            return -1;
        }
        if(m.find(key)!=m.end()){
            Node * res = m[key];
            int ans = res->val;
            res->freq = res->freq + 1;
            deleteNode(res);
            Node * result =  insertNode(res->key,res->val,res->freq);
            m.erase(res->key);
            m[key] = result;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cap<=0)
            return ;
       if(m.find(key)!=m.end()){
           Node * res = m[key];
           deleteNode(res);
           res->freq = res->freq + 1;
           Node * result =  insertNode(res->key,value,res->freq);
           m.erase(res->key);
           m[key] = result;
       }else{
           if(m.size()<cap){
               Node *res = insertNode(key,value,1);
               m[key] = res;
           }else{
               Node * delNode = freq[minFreq].second;
               delNode = delNode->prev;
               deleteNode(delNode);
               m.erase(delNode->key);
               Node *res = insertNode(key,value,1);
               m[key] = res;
           }
       }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */