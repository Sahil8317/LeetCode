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
   void calDepth(TreeNode *root,int &ans, int route){
       if(root==NULL)
           return ;
       if(root->left==NULL && root->right==NULL){
           route++;
           ans = min(ans,route);
           return ;
       }
        route++;
        calDepth(root->left,ans,route);
        calDepth(root->right,ans,route);
          
       
   }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ans = INT_MAX;
        int route = 0;
        calDepth(root,ans,route);
        return ans;
    }
};