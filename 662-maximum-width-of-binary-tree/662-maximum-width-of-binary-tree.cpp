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
    int widthOfBinaryTree(TreeNode* root) {
      int ans = INT_MIN;
      queue<pair<TreeNode*,int>> q;
      q.push({root,1});
        while(!q.empty()){
            int s = q.size();
            int first=0,last=0;
            pair< TreeNode*,int> w= q.front();
            int mmin = w.second;
            for(int i=0;i<s;i++){
               pair< TreeNode*,int> p = q.front();
                int curr = p.second - mmin;  // reindexing at each level
                q.pop();
                if(i==0) first =curr;
                if(i==s-1) last = curr;
                if(p.first->left) q.push({p.first->left,(2*curr)});
                if(p.first->right) q.push({p.first->right,(2*curr)+1});
            }
            ans = max((last-first+1),ans);
        }
        return ans;
    }
};