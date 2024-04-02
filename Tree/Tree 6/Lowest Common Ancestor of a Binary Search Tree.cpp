/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        else if(root->val>(min(p->val,q->val)) && root->val<(max(p->val,q->val))){
            return root;
        }
        else if(root->val<p->val && root->val<q->val){
            return lca(root->right,p,q);
        }
        else{
            return lca(root->left,p,q);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};
