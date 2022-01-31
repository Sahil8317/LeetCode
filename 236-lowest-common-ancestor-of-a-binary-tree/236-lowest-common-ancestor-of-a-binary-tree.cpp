/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode * getPath(TreeNode *root,TreeNode*p,TreeNode*q){
     if(root==NULL || root==p|| root==q){
         return root;
     }
      TreeNode* left =   getPath(root->left,p,q);
      TreeNode *right = getPath(root->right,p,q);
      if(left==NULL)
          return right;
      else if(right==NULL)
          return left;
        else{
          return root;
        }
     
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   
        return getPath(root,p,q);
    }
};