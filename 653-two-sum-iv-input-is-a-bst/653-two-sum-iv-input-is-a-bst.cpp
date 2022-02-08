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
    void getInorder(TreeNode *root,vector<int> &inorder){
        if(!root)
            return ;
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
    }
  
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return false;
       vector<int> inorder;
       getInorder(root,inorder);
       map<int,int> m;
        for(auto &i:inorder){
            m[i]+= 1;
        }
     for(auto &i:inorder){
         int diff = k-i;
         m[i] = 0;
         if(m[diff]!=0)
             return true;
     }
        return false;
    }
};