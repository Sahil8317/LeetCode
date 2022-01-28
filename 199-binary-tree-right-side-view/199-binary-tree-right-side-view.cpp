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
    
   void rRightSideView(TreeNode *p,int level ,vector<int> &ans){
      if(p==NULL)
          return ;
       if(ans.size()==level){
           ans.push_back(p->val);
       }
       rRightSideView(p->right,level+1,ans);
       rRightSideView(p->left,level+1,ans);
   }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rRightSideView(root,0,ans);
        return ans;
    }
};