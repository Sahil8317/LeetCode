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
    
    void recursiveInorderTraversal(TreeNode *root,vector<int> &ans){
        if(!root) return ;
        recursiveInorderTraversal(root->left,ans);
        ans.push_back(root->val);
        recursiveInorderTraversal(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
      // vector<int> ans;
      //   stack<TreeNode *> stk;
      //   TreeNode * p = root;
      //   while(true){
      //       if(p!=NULL){
      //           stk.push(p);
      //           p = p->left;
      //       }else{
      //           if(stk.empty()) break;
      //           p = stk.top();
      //           stk.pop();
      //           ans.push_back(p->val);
      //           p = p->right;
      //       }
      //   }
      //   return ans;
        vector<int> ans;
        recursiveInorderTraversal(root,ans);
        return ans;
    }
    
    
};