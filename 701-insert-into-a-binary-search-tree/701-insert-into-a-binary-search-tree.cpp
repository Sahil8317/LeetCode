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
    TreeNode* insertNode(TreeNode *root,int val){
        if(!root){
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if(val>root->val){
            root->right = insertNode(root->right,val);
        }else if(val<root->val){
            root->left = insertNode(root->left,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        return insertNode(root,val);
    }
};