/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/



class Solution {
private:
    unordered_map<int, Node*> visited;

    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (visited.find(node->val) != visited.end()) return visited[node->val];

        Node* newNode = new Node(node->val);
        visited[node->val] = newNode;

        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor));
        }
        return newNode;
    }

public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
