class Node{
    public:
    Node* links[26];
    bool flag =false;
    bool isContainCharacter(char c){
        return (links[c-'a']!=NULL);
    }
    void putCharacter(char c,Node *n){
        links[c-'a'] = n;
    }
    Node * moveNext(char c){
        return links[c-'a'];
    }
    
    bool getEnd(){
        return flag;
    }
    
};


class Trie {
private:
    Node *root;
public:
    Trie() {
    root = new Node();
    }
    
    void insert(string word) {
        Node* head = root;
        for(int i=0;i<word.size();i++){
          if(!head->isContainCharacter(word[i])){
              head->putCharacter(word[i],new Node());
            }  
            head = head->moveNext(word[i]);
        }
        head->flag = true;
        
    }
    
    bool search(string word) {
        Node *head = root;
        for(int i=0;i<word.size();i++){
            if(!head->isContainCharacter(word[i])){
                return false;
            }
            head = head->moveNext(word[i]);
        }
        return head->getEnd();
        
    }
    
    bool startsWith(string prefix) {
        Node *head = root;
        for(int i=0;i<prefix.size();i++){
            if(!head->isContainCharacter(prefix[i])){
                return false;
            }
            head = head->moveNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */