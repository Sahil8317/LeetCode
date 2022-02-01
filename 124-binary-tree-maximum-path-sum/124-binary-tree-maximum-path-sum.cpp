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
    int getSum(TreeNode *t,int &sum){
    if(t==NULL)
        return 0;
    
    int leftSum = max(0,getSum(t->left,sum));
    int rightSum = max(0,getSum(t->right,sum));
    sum = max(sum,(leftSum+rightSum+t->val));
    return t->val+max(leftSum,rightSum);

}
    
    int maxPathSum(TreeNode* root) {
        if(!root)   
            return 0;
        int sum =INT_MIN;
        getSum(root,sum);
        return sum;
    }
};