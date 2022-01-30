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
    int checkBalance(TreeNode*p,bool &flag){
        if(!p)
            return 0;
        int x = checkBalance(p->left,flag)+1;
        int y = checkBalance(p->right,flag)+1;
        if(abs(x-y)>1)
            flag = false;
        return max(x,y);
        
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        bool ans = true;
        checkBalance(root,ans);
        return ans;
    }
};