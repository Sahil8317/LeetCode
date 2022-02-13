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
    
    void sumNodes(TreeNode *root,vector<int> &ans,int sum){
        if(!root) return ;
            sum = sum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(sum);
        }
        sumNodes(root->left,ans,sum);
        sumNodes(root->right,ans,sum);
        
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        vector<int> res;
        sumNodes(root,res,0);
        for(auto &i:res){
            ans+=i;
        }
        return ans;
    }
};