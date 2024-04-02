int ceil(Node* root, int input,int &ans){
    if(!root) return -1;
    if(root->data==input){
        ans=root->data;
        return root->data;
    }
    else if(root->data<input){
        return ceil(root->right,input,ans);
    }
    else{
        ans=root->data;
        return ceil(root->left,input,ans);
    }
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans=-1;
    ceil(root,input,ans);
    return ans;
