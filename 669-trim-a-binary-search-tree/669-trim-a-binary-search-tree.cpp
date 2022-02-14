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
    
    void  trimTree(TreeNode *root,int low,int high,TreeNode *prev){
        if(!root) return ;
        TreeNode*node = root;
        if((node->val>=low && node->val<=high)){
            prev = root;
        }
        if(prev!=NULL && node->val<low){
           prev->left = node->right; 
        }
        if(prev!=NULL && node->val>high){
            prev->right = node->left;
        }
        trimTree(node->left,low,high,prev);
        trimTree(node->right,low,high,prev);
        
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
         
        if (root == NULL) return NULL;
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    
    }
};