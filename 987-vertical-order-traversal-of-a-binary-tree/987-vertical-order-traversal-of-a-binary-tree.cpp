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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int s = q.size();
            map<int,vector<int>> levelNode;
            for(int i=0;i<s;i++){
             pair<TreeNode*,int> p = q.front();
            int line = p.second;
            TreeNode * t = p.first;
            if(t->left) q.push({t->left,line-1});
            if(t->right) q.push({t->right,line+1});
            vector<int> vec = levelNode[line];
            vec.push_back(t->val);
            levelNode[line] = vec;
             q.pop();
            }
            for(auto &i:levelNode){
                vector<int> vec = i.second;
                sort(vec.begin(),vec.end());
                vector<int> res = m[i.first];
                for(auto j:vec){
                    res.push_back(j);
                }
                m[i.first] = res;
            }
        }
        for(auto &i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};