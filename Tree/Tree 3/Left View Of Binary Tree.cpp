vector<int> printLeftView(BinaryTreeNode<int>* root) {
    
    vector<int> ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        bool f=false;
        int c=q.size();
        while(c--){
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            if(!f){
                f=true;
                ans.push_back(node->data);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return ans;
}
