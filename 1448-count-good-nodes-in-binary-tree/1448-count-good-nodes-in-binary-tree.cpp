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
    void getGoodNodes(TreeNode *node,int mmax,int &ans){
        if(!node) return ;
        if(node->val>=mmax) ans++;
        mmax = max(mmax,node->val);
        getGoodNodes(node->left,mmax,ans);
        getGoodNodes(node->right,mmax,ans);
        
    }
    int goodNodes(TreeNode* root) {
       if(!root) return 0;
        int ans =0;
        getGoodNodes(root,INT_MIN,ans);
        return ans;
    }
};