#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define read(v, n)              \
    for (int i = 0; i < n; ++i) \
        cin >> v[i];
const int mod = (int)1e9 + 7;
struct TrieNode
{
    int count[2];
    int next[2];
    TrieNode()
    {
        count[0] = count[1] = 0;
        next[0] = next[1] = -1;
    }
};

void addNumber(vector<TrieNode> &trie, int number)
{
    int index = 0;
    for (int bitPosition = 20; bitPosition >= 0; --bitPosition)
    {
        bool bit = number & (1 << bitPosition);
        if (trie[index].next[bit] == -1)
        {
            trie[index].next[bit] = trie.size();
            trie.push_back(TrieNode());
        }
        trie[index].count[bit]++;
        index = trie[index].next[bit];
    }
}

ll queryTrie(const vector<TrieNode> &trie, int prefixXor, int threshold)
{
    int index = 0;
    ll result = 0;
    for (int bitPosition = 20; bitPosition >= 0; --bitPosition)
    {
        if (index == -1)
            break;
        bool thresholdBit = threshold & (1 << bitPosition);
        bool prefixBit = prefixXor & (1 << bitPosition);
        if (thresholdBit)
        {
            result += trie[index].count[prefixBit];
            index = trie[index].next[1 - prefixBit];
        }
        else
        {
            index = trie[index].next[prefixBit];
        }
    }
    return result;
}
void solve()
{
    int arraySize, threshold;
    cin >> arraySize >> threshold;

    vector<TrieNode> trie;
    ll solution = 0;
    trie.push_back(TrieNode());
    addNumber(trie, 0);

    int currentNumber, prefixXor = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        cin >> currentNumber;
        prefixXor ^= currentNumber;
        solution += queryTrie(trie, prefixXor, threshold);
        addNumber(trie, prefixXor);
    }
    cout << solution << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
