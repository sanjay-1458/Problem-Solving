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
    bool isleaf(TreeNode*root){
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return false;
    }
    void fun(TreeNode* root, int t,vector<vector<int>> &ans,vector<int> temp){
        if(!root) return;
        t=t-root->val;
        temp.push_back(root->val);
        // if(t<0) return;
        if(t==0 && isleaf(root)){
            ans.push_back(temp);
            return;
        }
        fun(root->left,t,ans,temp);
        fun(root->right,t,ans,temp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        fun(root,t,ans,{});
        return ans;
    }
};
