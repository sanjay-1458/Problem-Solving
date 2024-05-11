
struct TrieNode {
    TrieNode* branches[2];
    int count = 0;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (temp->branches[bit] == nullptr) {
                TrieNode* new_branch = new TrieNode();
                temp->branches[bit] = new_branch;
            }
            temp = temp->branches[bit];
            temp->count++;
        }
    }
    
    int countPairsWithPrefix(TrieNode* node, int index, int num, int max_value) {
        if (node == nullptr) {
            return 0;
        }
        if (index < 0) {
            return node->count;
        }
        int ans = 0;
        int num_bit = (num >> index) & 1;
        int max_value_bit = (max_value >> index) & 1;
        if (num_bit == 1) {
           if (max_value_bit == 1) {
               if (node->branches[1] != nullptr) {
               ans += node->branches[1]->count;
               }
             ans += countPairsWithPrefix(node->branches[0], index - 1, num, max_value);
           }
           else {
              ans += countPairsWithPrefix(node->branches[1], index - 1, num, max_value);
           }
        }
        else {
          if (max_value_bit == 1) {
              if (node->branches[0] != nullptr) {
            ans += node->branches[0]->count;
              }
            ans += countPairsWithPrefix(node->branches[1], index - 1, num, max_value);
          }
          else {
              ans += countPairsWithPrefix(node->branches[0], index - 1, num, max_value);
          }
        }
        return ans;
    }
};

class Solution {
public:
    int countPairs(vector<int>& numbers, int lower_limit, int upper_limit) {
         Trie trie;
         int ans = 0;
         for (auto num : numbers) {
             int right_count = trie.countPairsWithPrefix(trie.root, 31, num, upper_limit);
             int left_count = trie.countPairsWithPrefix(trie.root, 31, num, lower_limit - 1);
             ans += (right_count - left_count);
             trie.insert(num);
         }   
         return ans;
    }
};
