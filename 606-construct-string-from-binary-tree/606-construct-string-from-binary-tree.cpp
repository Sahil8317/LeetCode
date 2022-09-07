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
    string explore(TreeNode *node){
       string ans = to_string(node->val);
       if(node->left){
           ans+="("+explore(node->left)+")";
       }  
       if(node->right){
           if(!node->left)
               ans+="()";
           ans+="("+explore(node->right)+")";
       }
        return ans;
    }
    
    string tree2str(TreeNode* root) {
        return explore(root);
    }
};