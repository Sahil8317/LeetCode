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
    TreeNode * tree(vector<int> in,int inStart,int inEnd,vector<int> pre,int preStart,int preEnd){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[preStart]);
        int index = 0;
        for(int i=inStart;i<=inEnd;i++){
            if(in[i]==pre[preStart]){
                index = i;
                break;
            }
        }
        int numLeft = index-inStart;
        root->left = tree(in,inStart,index-1,pre,preStart+1,preStart+numLeft);
        root->right = tree(in,index+1,inEnd,pre,preStart+numLeft+1,preEnd);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()|| inorder.empty())
            return NULL;
        TreeNode *ans = tree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
        return ans;
    }
};