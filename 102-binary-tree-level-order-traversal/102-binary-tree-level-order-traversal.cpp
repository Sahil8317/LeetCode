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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> res;
            int s = q.size();
           for(int i=0;i<s;i++){
            TreeNode *t = q.front();
            res.push_back(q.front()->val);
            q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};