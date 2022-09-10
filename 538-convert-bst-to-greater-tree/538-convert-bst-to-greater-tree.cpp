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
    //initial approach
//     int sumOfNodes(TreeNode *node,int root){
//         if(node->left==NULL && node->right==NULL && root!=0){
//             int temp = node->val;
//             node->val+=root;
//             return temp;
//         }
//         if(!node->left && !node->right) return node->val;
//         if(root!=0){
//             // means we are on left side of tree
//             int temp= node->val;
//             node->val+=root;
//             if(node->right){
//                 int k=sumOfNodes(node->right,root);
//                 temp+=k;
//                 node->val+=k;
//             }
//             int n = 0;
//             if(node->left) 
//                 n =  sumOfNodes(node->left,node->val);
//             return temp+n;
//         }
//         if(node->right)
//             node->val+=sumOfNodes(node->right,0);
//         int ans = 0;
//         if(node->left)
//              ans = sumOfNodes(node->left,node->val);
//         return node->val+ans;
            
//     }
    
    // best solution
    // inorder traversal with carrying a variable total 
    //  right root left 
    void travelNodes(TreeNode *node,int &total){
        if(!node) return;
        travelNodes(node->right,total);
        total+=node->val;
        node->val = total;
        travelNodes(node->left,total);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        if(root)
            travelNodes(root,total);
        return root;
    }
};