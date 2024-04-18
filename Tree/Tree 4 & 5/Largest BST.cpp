struct NodeL{
    int maxi, mini, size;
    bool bst;
    NodeL(){
        maxi = INT_MIN;
        mini = INT_MAX;
        size = 0;
        bst = true;
    }
};
class Solution{
    NodeL dfs(Node* root, int &maxSize){
        if(root == nullptr) {
            NodeL ptr;
            return ptr;
        }
        NodeL res;
        NodeL left = dfs(root->left, maxSize);
        NodeL right = dfs(root->right, maxSize);
        if(!left.bst || !right.bst || root->data <= left.maxi || root->data >= right.mini){
            res.bst = false;
            return res;
        }
        res.size = left.size + right.size + 1;
        res.mini = min(left.mini, root->data);
        res.maxi = max(right.maxi, root->data);
        res.bst = true;
        maxSize = max(maxSize, res.size);
        return res;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int maxSize = 0;
        dfs(root, maxSize);
        return maxSize;
    	//Your code here
    }
