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
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        if(root == nullptr) return 0;
        int depth = 0;
        while(!nodeQueue.empty()){
            int levelSize = nodeQueue.size();
            while(levelSize--){
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                if(currentNode->left != nullptr) nodeQueue.push(currentNode->left);
                if(currentNode->right != nullptr) nodeQueue.push(currentNode->right);
            }
            depth++;
        }
        return depth;
    }
};
