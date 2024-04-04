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

    TreeNode* fun(vector<int>&v,int l,int h){
        if(l==h){
            TreeNode*t=new TreeNode(v[l]);
            return t;
        }
        if(l>h){
            return nullptr;
        }
        TreeNode *root=new TreeNode(v[l]);
        int nl=l+1,nh=l+1;
        for(int i=l;i<=h;++i){
            if(v[i]<=v[l]){
                nh=i;
            }
            else{
                break;
            }
        }
        root->left=fun(v,nl,nh);
        root->right=fun(v,nh+1,h);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return fun(preorder,0,n-1);
    }
};
