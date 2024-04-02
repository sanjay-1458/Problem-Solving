
#include<bits/stdc++.h>
void inorder(TreeNode<int> *node,vector<int>&t){
    if(node==nullptr) return;
    inorder(node->left,t);
    if(node->left==nullptr && node->right==nullptr){
        t.push_back(node->data);
    }
    inorder(node->right,t);
}

bool leaf(TreeNode<int>* node){
    if(node->left==nullptr && node->right==nullptr) return true;
    return false;
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int>l,b,r;
    TreeNode<int> *node=root;
    node=root->left;
    while(node){
        if(!leaf(node)) l.push_back(node->data);
        if(node->left!=nullptr) node=node->left;
        else node=node->right;
    }
    node=root->right;
    while(node){
        if(!leaf(node)) r.push_back(node->data);
        if(node->right!=nullptr) node=node->right;
        else node=node->left;
    }
    reverse(r.begin(),r.end());
    inorder(root,b);
    vector<int> ans;
    ans.push_back(root->data);
    ans.insert(ans.end(),l.begin(),l.end());
    ans.insert(ans.end(),b.begin(),b.end());
    ans.insert(ans.end(),r.begin(),r.end());
    return ans;
}
