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
    int calTree(TreeNode*p,int&maxi){
        if(!p)
            return 0;
        int x = calTree(p->left,maxi);
        int y = calTree(p->right,maxi);
        maxi = max(maxi,x+y);
        return 1+max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int ans = 0;
        calTree(root,ans);
        
        
        // // brute force
        // queue<TreeNode*>q;
        // q.push(root);
        // int ans = INT_MIN;
        // while(!q.empty()){
        //     TreeNode * t = q.front();
        //     q.pop();
        //     if(t->left)q.push(t->left);
        //     if(t->right)q.push(t->right);
        //     int x = calTree(t->left)+calTree(t->right);
        //     ans = max(ans,x);
        // }
        return ans;
    }
};