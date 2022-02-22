/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * createGraph(Node *node,map<int,Node*> &vis){
    if(node==NULL) return NULL;
        if(vis.find(node->val)!=vis.end()) return vis[node->val];
        Node *newNode = new Node(node->val);
        vis[node->val] = newNode;
        vector<Node*> neigh;
        for(auto i:node->neighbors){
           Node *n = createGraph(i,vis); 
           neigh.push_back(n);
        }
        newNode->neighbors = neigh;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
       map<int,Node*> vis;
       return createGraph(node,vis);
    }
};