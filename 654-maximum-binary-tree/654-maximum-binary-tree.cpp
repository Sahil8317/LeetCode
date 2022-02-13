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
   pair<int,int> getMax(vector<int> nums,int s,int e){
        int ans = INT_MIN;
        int index = 0;
        for(int i=s;i<=e;i++){
            if(nums[i]>ans){
                ans = nums[i];
                index = i;
            }
        }
        return {index,ans};
    }
    
    TreeNode* buildTree(TreeNode *&root,vector<int> nums,int s,int e){
        if(s>e) return NULL;
        pair<int,int> mmax = getMax(nums,s,e);
        int mIndex = mmax.first;
        TreeNode *node = new TreeNode(mmax.second);
        if(!root) root = node;
        node->left = buildTree(root,nums,s,mIndex-1);
        node->right = buildTree(root,nums,mIndex+1,e);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TreeNode*root=NULL;
        buildTree(root,nums,0,nums.size()-1);
        return root;
    }
};