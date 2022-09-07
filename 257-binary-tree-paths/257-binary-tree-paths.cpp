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
    
    void explorePaths(TreeNode *node, string ans, vector<string> &fans){
        ans+=to_string(node->val);
        if(node!=NULL && node->left==NULL && node->right==NULL){
            fans.push_back(ans);
            return ;
        }
        ans+="->";
        if(node->left){
            explorePaths(node->left,ans,fans);
        }
        if(node->right){
            explorePaths(node->right,ans,fans);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        explorePaths(root,"",ans);
        return ans;
    }
};