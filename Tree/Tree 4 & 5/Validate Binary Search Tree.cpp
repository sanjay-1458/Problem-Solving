class Solution {
    bool preorder(TreeNode* root,long low,long high){
        if(!root) return true;
        if(root->val<=low || root->val>=high){
            return false;
        }
        bool left=preorder(root->left,low,root->val);
        bool right=preorder(root->right,root->val,high);
        return (left && right);
    }
public:
    bool isValidBST(TreeNode* root) {
        long low=LONG_MIN,high=LONG_MAX;
        // if(!root->left && !root->right) return true;
        return preorder(root,low,high);
    }
};
