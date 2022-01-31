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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        deque<TreeNode *> d;
        d.push_front(root);
        int levelCount = 0;
        while(!d.empty()){
            int s = d.size();
            vector<int> res;
            if(levelCount%2==0){
                // use FIFO
            for(int i=0;i<s;i++){
                TreeNode *t = d.front();
                res.push_back(t->val);
                if(t->left)d.push_back(t->left);
                if(t->right)d.push_back(t->right);
                d.pop_front();
            }
                
            }else{
                // use LIFO
                for(int i=0;i<s;i++){
                    TreeNode *t = d.back();
                    res.push_back(t->val);
                    d.pop_back();
                    d.push_front(t);
                }
                for(int i=0;i<s;i++){
                    TreeNode*t = d.front();
                    if(t->left)d.push_back(t->left);
                    if(t->right)d.push_back(t->right);
                    d.pop_front();
                }
            }
            ans.push_back(res);
            levelCount++;
        }
        return ans;
    }
};