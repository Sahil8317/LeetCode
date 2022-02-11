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
    
   void findNodes(TreeNode *root,TreeNode*&prev,TreeNode*&first,TreeNode*&second){
       if(root==NULL)
           return ;
       findNodes(root->left,prev,first,second);
       if(first==NULL && prev!=NULL && prev->val>=root->val){
           first = prev;
       }
       if(first!=NULL && prev!=NULL && prev->val>=root->val){
           second = root;
       }
       prev = root;
       findNodes(root->right,prev,first,second);
       
   }
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL,*second = NULL;
        TreeNode *prev = NULL;
        findNodes(root,prev,first,second);
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
      
};