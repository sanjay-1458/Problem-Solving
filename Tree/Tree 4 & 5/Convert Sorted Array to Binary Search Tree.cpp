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
    TreeNode* fun(vector<int>&nums,int l,int h){
        if(l==h){
            TreeNode* t=new TreeNode(nums[l]);
            return t;
        }
        if(l>h){
            return nullptr;
        }
        int mid=(l+h)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=fun(nums,l,mid-1);
        root->right=fun(nums,mid+1,h);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return fun(nums,0,n-1);
    }
};
