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
struct Node{
    int maxi,mini,tsum=0;
    bool bst=true;
    Node(){
        maxi=INT_MIN;
        mini=INT_MAX;
    }
};
class Solution {
    Node dfs(TreeNode* root,int &ans){
        if(root==nullptr) {
            Node ptr;
            return ptr;
        }
        Node res;
        Node left=dfs(root->left,ans);
        Node right=dfs(root->right,ans);
        if(!left.bst || !right.bst|| root->val<=left.maxi || root->val>=right.mini){
            res.bst=false;
            return res;
        }
        res.tsum=left.tsum+right.tsum+root->val;
        res.mini=min(left.mini,root->val);
        res.maxi=max(right.maxi,root->val);
        ans=max(ans,res.tsum);
        return res;
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        Node res;
        res=dfs(root,ans);
        return ans;
    }
};
