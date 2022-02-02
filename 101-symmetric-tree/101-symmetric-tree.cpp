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
    
    void check(TreeNode *left,TreeNode *right ,bool &ans){
        if(!left && right || left &&!right){
            ans = false;
            return ;
        }
        if(left==NULL || right==NULL)
            return ;
        if(left->val!=right->val){
            ans = false;
            return ;
        }
        check(left->left,right->right,ans);
        check(left->right,right->left,ans);   
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = true;
        if(!root)
            return ans;
        check(root->left,root->right,ans);
        return ans;
        
    }
};