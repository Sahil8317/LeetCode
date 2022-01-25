class Node{
public:
    int key;
    int val;
    Node * next;
    Node * prev;
    
    Node(int k,int v){
        key = k;
        val = v;
    }

};

class LRUCache {
private:
    Node *head ;
    Node *tail ;
    int cap;
    unordered_map<int,Node *> m;
public:
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
        cap = capacity;
    }
    Node * insertNode(int k,int v){
        Node *newNode = new Node(k,v);
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        return newNode;
    }
    
    void deleteNode(Node * node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
    }
    
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node * res = m[key];
            int ans = res->val;
            deleteNode(res);
            Node *result =  insertNode(res->key,res->val);
            m.erase(key);
            m[key] = result;
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node * delNode = m[key];
            deleteNode(delNode);
            m.erase(delNode->key);
           } 
        if(m.size()<cap){
              Node * res = insertNode(key,value);
              m[key] = res;
        }else{
            Node * delNode = tail->prev;
            deleteNode(delNode);
            Node * res = insertNode(key,value);
            m.erase(delNode->key);
            m[key] = res;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */