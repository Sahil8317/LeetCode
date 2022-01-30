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
    
    void getSum(TreeNode *p,int target,bool &flag,int sum){
        if(p==NULL){
            return ;
        }
        if(p->left==NULL && p->right==NULL){
            if((sum+p->val)==target)
                flag = true;
            return ;
        }
         getSum(p->left,target,flag,sum+p->val);
         getSum(p->right,target,flag,sum+p->val);
       
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        bool ans= false;
         getSum(root,targetSum,ans,0);
        return ans;
    }
};