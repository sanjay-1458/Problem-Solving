/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void fun(TreeNode* A, int B,vector<int> &ans,vector<int> t){
    if(A==nullptr) return;
    t.push_back(A->val);
    if(A->val==B){
        ans=t;
        return;
    }
    fun(A->left,B,ans,t);
    fun(A->right,B,ans,t);
    
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    fun(A,B,ans,{});
    return ans;
}
