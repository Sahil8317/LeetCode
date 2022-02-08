/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inorder;
    int index ;
    
    void getInorder(TreeNode *root){
        if(!root)
            return ;
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }
    BSTIterator(TreeNode* root) {
    getInorder(root);
    index = -1;
    }
    
    int next() {
    index++;
    return inorder[index];
    }
    
    
    bool hasNext() {
       if((index+1)<inorder.size())
           return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */