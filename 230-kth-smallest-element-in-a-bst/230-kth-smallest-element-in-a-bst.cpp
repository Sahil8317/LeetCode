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
    // brute force
    // void inorder(TreeNode *root,vector<int> &ans){
    //     if(!root)
    //         return ;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    
    void getNode(TreeNode *root,int &k,int &ans){
        if(!root)
            return ;
        getNode(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val;
            return ;
        }
        getNode(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        int ans = -1;
        getNode(root,k,ans);
        return ans;
    }
};