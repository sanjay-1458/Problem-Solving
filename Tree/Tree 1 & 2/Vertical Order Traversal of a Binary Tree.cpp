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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<pair<int,int>,vector<int>> verticalMap;
        queue<pair<TreeNode*,pair<int,int>>> nodeQueue;
        nodeQueue.push({root,{0,0}});
        while(!nodeQueue.empty()){
            TreeNode* currentNode = nodeQueue.front().first;
            int xCoordinate = nodeQueue.front().second.first;
            int yCoordinate = nodeQueue.front().second.second;
            nodeQueue.pop();
            verticalMap[{xCoordinate, yCoordinate}].push_back(currentNode->val);
            if(currentNode->left != nullptr){
                nodeQueue.push({currentNode->left, {xCoordinate - 1, yCoordinate + 1}});
            }
            if(currentNode->right != nullptr){
                nodeQueue.push({currentNode->right, {xCoordinate + 1, yCoordinate + 1}});
            }
        }
        map<int,vector<int>> orderedMap;
        vector<vector<int>> result;
        for(auto &pair : verticalMap){
            vector<int> values = pair.second;
            sort(values.begin(), values.end());
            int xCoordinate = pair.first.first;
            for(int i = 0; i < values.size(); ++i){
                orderedMap[xCoordinate].push_back(values[i]);
            }
        }
        for(auto &pair : orderedMap){
            result.push_back(pair.second);
        }
        return result;
    }
};
