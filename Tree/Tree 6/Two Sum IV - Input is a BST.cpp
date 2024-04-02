
class Solution {
    bool preorder(TreeNode* root, int k,unordered_map<int,int>&mp){
        if(!root) return false;
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp[root->val]++;
        bool left=preorder(root->left,k,mp);
        if(left){
            return true;
        }
        bool right=preorder(root->right,k,mp);
        if(right){
            return true;
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        return preorder(root,k,mp);
    }
};
