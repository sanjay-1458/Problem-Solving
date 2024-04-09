struct TrieNode{
    TrieNode* childs[26];
    int prefix=0;
    bool contain(char ch){
        return (childs[ch-'a']!=nullptr);
    }
    void put(char ch,TrieNode* node){
        childs[ch-'a']=node;
    }
    TrieNode*get(char ch){
        return childs[ch-'a'];
    }
    void incPrefix(){
        prefix+=1;
    }
    int getPrefix(){
        return prefix;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string &word){
        TrieNode*node=root;
        for(int i=0;i<word.size();++i){
            if(!node->contain(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
            node->incPrefix();
        }
    }
    int count(string &word){
        TrieNode*node=root;
        int ans=0;
        for(int i=0;i<word.size();++i){
            if(node->contain(word[i])){
                node=node->get(word[i]);
                ans+=node->getPrefix();
            }
            else{
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        vector<int> ans(n);
        Trie trie;
        for(int i=0;i<n;++i){
            trie.insert(words[i]);
        }
        for(int i=0;i<n;++i){
            ans[i]=trie.count(words[i]);
        }
        return ans;
    }
};
