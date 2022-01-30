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
    
    int calDepth(TreeNode * p){
        if(p==NULL){
            return 0;
        }
       int x = calDepth(p->left)+1;
        int y = calDepth(p->right)+1;
        if(x>y)
            return x;
        else
            return y;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return calDepth(root);
    }
};