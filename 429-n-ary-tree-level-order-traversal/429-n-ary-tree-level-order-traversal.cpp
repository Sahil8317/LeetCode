/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                Node *newNode = q.front();
                q.pop();
                temp.push_back(newNode->val);
                for(Node *childNode : newNode->children){
                    if(childNode)
                        q.push(childNode);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};