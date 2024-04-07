struct TrieNode{
    TrieNode* childNode[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;++i){
            childNode[i]=nullptr;
        }
        isEndOfWord=false;
    }
    bool containKey(char ch){
        return (childNode[ch-'a']!=nullptr);
    }
    void put(char ch,TrieNode* node){
        childNode[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return childNode[ch-'a'];
    }
    void setEnd(){
        isEndOfWord=true;
    }
    bool getEnd(){
        return isEndOfWord;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode*node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode *node=root;
        for(int i=0;i<word.size();++i){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
            }
            else{
                return false;
            }
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.size();++i){
            if(node->containKey(prefix[i])){
                node=node->get(prefix[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
