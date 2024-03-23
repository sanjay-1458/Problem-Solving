/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int fun(TreeNode<int> *root){
    if(root==nullptr) return 0;
    int left=fun(root->left)+1;
    int right=fun(root->right)+1;
    return max(left,right);
}

int heightOfBinaryTree(TreeNode<int> *root)
{
    return fun(root);
}
