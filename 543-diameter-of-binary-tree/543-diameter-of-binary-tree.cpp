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
    int calTree(TreeNode*p){
        if(!p)
            return 0;
        int x = calTree(p->left)+1;
        int y = calTree(p->right)+1;
        if(x>y)
            return x;
        else
            return y;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans = INT_MIN;
        while(!q.empty()){
            TreeNode * t = q.front();
            q.pop();
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
            int x = calTree(t->left)+calTree(t->right);
            ans = max(ans,x);
        }
        return ans;
    }
};