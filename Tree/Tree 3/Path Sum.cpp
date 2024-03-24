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
    bool leaf(TreeNode* node){
        if(node->left==nullptr && node->right==nullptr) return true;
        else return false;
    }
    bool fun(TreeNode* node,int s){
        if(node==nullptr) return false;
        if(s- node->val==0 && leaf(node)){
            return true;
        }
        bool x=fun(node->left,s-node->val);
        bool y=fun(node->right,s-node->val);
        return (x || y);
    }
public:
    bool hasPathSum(TreeNode* root, int t) {
        return fun(root,t);
    }
};
