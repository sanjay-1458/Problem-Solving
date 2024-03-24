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
    int funh(TreeNode* node,int& maxi){
    if(node==nullptr){
        return 0;
    }
    int lh=funh(node->left,maxi);
    int rh=funh(node->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
            int val=0;
	funh(root,val);
    return val;
    }
};
