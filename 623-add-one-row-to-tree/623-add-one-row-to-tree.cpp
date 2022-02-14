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
    TreeNode *addNodes(TreeNode *root,int val,int depth,int count,bool isLeft){
        if(root==NULL && count+1==depth){
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if(!root) return NULL;
        count++;
        if(depth==count && isLeft){
            TreeNode * node = new TreeNode(val);
            node->left = root;
            isLeft = false;
            return node;
        }else {
            if(depth==count && isLeft==false){
            TreeNode *node = new TreeNode(val);
            node->right = root;
            return node;
            }
        }
       root->left = addNodes(root->left,val,depth,count,true);     
       root->right = addNodes(root->right,val,depth,count,false);
        return root;
    }
   
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return new TreeNode(val);
        if(depth==1){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }else{
            bool isLeft = true;
           addNodes(root,val,depth,0,isLeft);
        }
        return root;
    }
};