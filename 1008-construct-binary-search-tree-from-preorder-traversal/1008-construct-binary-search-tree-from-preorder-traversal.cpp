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
       bool createBST(TreeNode * root,int ele){
        if(root==NULL)
            return false;
           
        if(ele<root->val){
         bool ans = createBST(root->left,ele);
            if(!ans)
                root->left = new TreeNode(ele,NULL,NULL);
            return true;
        }
        else{
           bool ans =  createBST(root->right,ele);
            if(!ans)
               root->right = new TreeNode(ele,NULL,NULL);
            return true;
        }
        
    }
        
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty())
            return NULL;
        TreeNode *root = new TreeNode(preorder[0],NULL,NULL);
        for(int i=1;i<preorder.size();i++){
            createBST(root,preorder[i]);
        }
        return root;
    }
};