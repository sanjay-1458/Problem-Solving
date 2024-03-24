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
    unordered_map<long long,long long> mp;
    void fun(TreeNode* root, long long t,long long &res,long long sum){
        if(!root) return;
        sum+=root->val;
        if(sum==t){
            res++;
        }
        if(mp.find(sum-t)!=mp.end()){
            res+=(mp[sum-t]);
        }
        mp[sum]++;
        fun(root->left,t,res,sum);
        fun(root->right,t,res,sum);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int t) {
        long long ans=0;
        fun(root,t,ans,0);
        return ans;
    }
};
