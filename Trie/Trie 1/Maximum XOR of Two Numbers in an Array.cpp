struct Node {
    Node *links[2];

    Node() {
        for(Node* &x:links){
            x=nullptr;
        }
    }

    bool contain(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }

};

class Trie {
private:
    Node* root;

public:
    Trie(){
        root=new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->contain(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxi(int num) {
        Node* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->contain(1 - bit)) {
                ans |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return ans;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int i = 0; i < nums.size(); ++i) {
            trie.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans = max(ans, trie.maxi(nums[i]));
        }
        return ans;
    }
};
