
class Solution {

    void inorder(TreeNode* node,TreeNode* &first,TreeNode*&second,TreeNode* &prev){
        if(!node) return;
        inorder(node->left,first,second,prev);
        if(prev==nullptr){
            prev=node;
        }
        else{
            if(node->val<prev->val){
                if(first==nullptr){
                    first=prev;
                }
                second=node;
            }
            prev=node;
        }
        inorder(node->right,first,second,prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode*first=nullptr,*second=nullptr;
        TreeNode*prev=nullptr;
        inorder(root,first,second,prev);
        swap(first->val,second->val);
    }
};
