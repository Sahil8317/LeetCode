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
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       stack<TreeNode *> stk;
        TreeNode *t = root;
        while(true){
            if(t!=NULL){
               stk.push(t);
                ans.push_back(t->val);
                t = t->left;
            }else{
                if(stk.empty())break;
               t = stk.top();
                stk.pop();
                t = t->right;
            }
        }
        return ans;
    }
};