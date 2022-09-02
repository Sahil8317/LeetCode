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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty()){
           int qSize = q.size();
           double avg = 0;
           long long sum = 0;
           for(int i=0;i<qSize;i++){
              TreeNode *node = q.front();
              sum+=node->val;
              q.pop();
           if(node->left) q.push(node->left);
           if(node->right) q.push(node->right);
           }
           avg = (double)sum/qSize;
           ans.push_back(avg);
             
        }
        return ans;
    }
};