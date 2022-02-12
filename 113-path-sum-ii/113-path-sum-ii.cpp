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
    void getPaths(TreeNode *root,int targetSum,vector<int> res,vector<vector<int>> &ans,int sum){
        if(root==NULL)return ;
        sum+=root->val;
        res.push_back(root->val);
       if(root->left==NULL && root->right==NULL){
          if(sum==targetSum){  
          ans.push_back(res);
          }
            return ;
       }
        
        getPaths(root->left,targetSum,res,ans,sum);
        getPaths(root->right,targetSum,res,ans,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> res;
        vector<vector<int>> ans;
          if(!root)
            return ans; 
        getPaths(root,targetSum,res,ans,0);
        return ans;
        
    }
};