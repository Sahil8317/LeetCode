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

// dp question dp on trees
class Solution {
public:
   int f(TreeNode *root, map<TreeNode*,int> &dp){
       if(root==NULL) return 0;
       if(dp[root]!=0) return dp[root];
       
       int pick = root->val;
       if(root->left){ 
           pick+=f(root->left->left,dp);
           pick+=f(root->left->right,dp);
       }
       if(root->right){
           pick+=f(root->right->left,dp);
           pick+=f(root->right->right,dp);
       }
       
       int notPick = 0+f(root->left,dp)+f(root->right,dp);
       
       return dp[root] =  max(pick,notPick);
    
       
   }
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        return f(root,dp);
    }
};