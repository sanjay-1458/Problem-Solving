
class Solution {
    void inorder(TreeNode* root, int k,int &cnt,int &ans){
        if(!root) return;
        inorder(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k && ans==-1){
            ans=root->val;
        }
        inorder(root->right,k,cnt,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        inorder(root,k,cnt,ans);
        return ans;
    }
};
