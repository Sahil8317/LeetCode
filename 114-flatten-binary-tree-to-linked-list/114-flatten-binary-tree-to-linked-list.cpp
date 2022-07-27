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
class Solution {
public:
    // recursive solution
    TreeNode *prev = NULL;
    void createLinkedList(TreeNode *root){
        if(!root)
            return ;
        createLinkedList(root->right);
        createLinkedList(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
        
    }
    void flatten(TreeNode* root) {
       createLinkedList(root);
    }
    
};