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
    
    TreeNode * tree(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart,int postEnd){
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode * root = new TreeNode(postorder[postEnd]);
        int index = 0;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i]==root->val){
                index = i;
                break;
            }
        }
        int numsLeft = index-inStart;
        root->left = tree(inorder,inStart,index-1,postorder,postStart,postStart+numsLeft-1);
        root->right = tree(inorder,index+1,inEnd,postorder,postStart+numsLeft,postEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty())
            return NULL;
        return tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};