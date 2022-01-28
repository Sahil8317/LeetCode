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
    
    void rInordertraversal(TreeNode *p,vector<int> &ans){
        if(p==NULL)
            return ;
        rInordertraversal(p->left,ans);
        ans.push_back(p->val);
        rInordertraversal(p->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
        rInordertraversal(root,ans);
        return ans;
    }
};