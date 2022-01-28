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
    void rPreorderTraversal(TreeNode *t,vector<int> &ans){
        if(t==NULL)
            return ;
        ans.push_back(t->val);
        rPreorderTraversal(t->left,ans);
        rPreorderTraversal(t->right,ans);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
        rPreorderTraversal(root,ans);
        return ans;
    }
};