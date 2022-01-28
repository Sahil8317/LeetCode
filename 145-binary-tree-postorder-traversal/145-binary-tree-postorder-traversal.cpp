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
    void rPostorderTraversal(TreeNode *t,vector<int> &ans){
        if(t==NULL)
            return ;
        rPostorderTraversal(t->left,ans);
        rPostorderTraversal(t->right,ans);
        ans.push_back(t->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        rPostorderTraversal(root,ans);
        return ans;
    }
};