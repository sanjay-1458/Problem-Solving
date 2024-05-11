#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define read(v, n) \
    for (int i = 0; i < n; ++i) cin >> v[i];
const int mod = (int)1e9 + 7;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

struct TrieNode
{
    TrieNode *childNode[26];
    bool isEndOfWord;
    vector<string> commonPrefixNames;
    TrieNode()
    {
        for (int i = 0; i < 26; ++i)
        {
            childNode[i] = nullptr;
        }
        isEndOfWord = false;
    }
    bool containKey(char ch)
    {
        return (childNode[ch - 'a'] != nullptr);
    }
    void put(char ch, TrieNode *node)
    {
        childNode[ch - 'a'] = node;
    }
    TrieNode *get(char ch)
    {
        return childNode[ch - 'a'];
    }
    void setEnd()
    {
        isEndOfWord = true;
    }
    bool getEnd()
    {
        return isEndOfWord;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
            node->commonPrefixNames.push_back(word.substr(i));
        }
        node->setEnd();
    }

    void query()
    {
        TrieNode *node = root;
        char input;
        while (true)
        {
            cout << "Enter character(s): ";
            cin >> input;
            if (input == '\0')
            {
                break;
            }
            int ind = input - 'a';
            if (!node->containKey(input))
            {
                cout << "No names available" << endl;
                break;
            }
            node = node->get(input);
            for (auto name : node->commonPrefixNames)
            {
                cout << name << " ";
            }
            cout << endl;
        }
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return false;
            }
        }
        return node->getEnd();
    }
};

void solve()
{
    Trie trie;
    vector<string> s = {"apple", "ant", "apxl"};

    for (auto X : s)
    {
        trie.insert(X);
    }
    trie.query();
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
