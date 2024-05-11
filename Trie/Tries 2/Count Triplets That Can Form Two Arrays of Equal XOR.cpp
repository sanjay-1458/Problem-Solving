// Brute Force
class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        int res =0;
        for(int i=0;i<n;i++)
        {
            int t = a[i];
            for(int k=i+1;k<n;k++)
            {
                t = t^a[k];
                if(t==0)
                    res+=(k-i);
            }
        }
        
        return res;
        
    }
};

// Trie
class TrieNode {
public:
    int prefix_count = 0;
    int sum_of_indices = 0;
    TrieNode* children[2] = {nullptr, nullptr};
    // void get{

    // }
};

class Solution {
public:
    void insert(TrieNode* root, int num, int index) {
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!root->children[bit])
                root->children[bit] = new TrieNode();
            root = root->children[bit];
        }
        root->sum_of_indices += index;
        root->prefix_count++;
    }

    int query(TrieNode* root, int num, int index) {
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!root->children[bit])
                return 0;
            root = root->children[bit];
        }
        return root->prefix_count * index - root->sum_of_indices;
    }

    int countTriplets(const vector<int>& arr) {
        const int MOD = (int)(1e9) + 7;
        long long answer = 0;
        int xor_value = 0;
        TrieNode* root = new TrieNode();
        for (size_t i = 0; i < arr.size(); ++i) {
            insert(root, xor_value, i);
            xor_value ^= arr[i];
            answer = (answer + query(root, xor_value, i)) % MOD;
        }
        return (int)(answer);
    }
};
