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
    void nodeSum(TreeNode *node,int target,int &ans,int sum,deque<int> res){
        if(node==NULL){
            return ;
        }
        if(node->val+sum==target){
            ans++;
            return ;
        }else if(node->val+sum<target){
            sum = sum+node->val;
            res.push_back(node->val);
        }else{
            if(!res.empty() )
              sum = sum+node->val;
           while(!res.empty()){
             int x = res.front();
             sum = sum-x;
             res.pop_front();
               if(sum==target)
                   ans++;
           } 
            
        }
        nodeSum(node->left,target,ans,sum,res);
        nodeSum(node->right,target,ans,sum,res);
    }
    // brute force
    void calSum(TreeNode *node,int sum,int &ans,int target){
        if(!node) return ;
        if(sum+node->val==target){
            ans++; 
        } 
            sum = sum+node->val;
            calSum(node->left,sum,ans,target);
            calSum(node->right,sum,ans,target);
        
    }
    void traverseTree(TreeNode *root,int target,int &ans){
        if(!root) return ;
        calSum(root,0,ans,target);
        traverseTree(root->left,target,ans);
        traverseTree(root->right,target,ans);
    }
    int pathSum(TreeNode * root,int target){
        int ans = 0;
        deque<int> dq;
        //nodeSum(root,target,ans,0,dq);
        traverseTree(root,target,ans);
        return ans;
    }
       
};