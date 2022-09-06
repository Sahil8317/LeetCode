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
    
    bool removeNodes(TreeNode* root){
        if(root==NULL)
            return false;
        if(root->val==0 && root->left==NULL && root->right==NULL)
            return true;
        bool leftNode = removeNodes(root->left);
        bool rightNode = removeNodes(root->right);
        if(leftNode)
            root->left=NULL;
        if(rightNode)
            root->right=NULL;
        if((leftNode && rightNode && root->val==0)||root->val==0 && root->left==NULL && root->right==NULL){
            // remove the present node also.
            return true;
        }
        return false;
    }
    
    
    
    TreeNode* pruneTree(TreeNode* root) {
       bool ans = removeNodes(root);
        if(ans)
            root=NULL;
        return root;
    }
};