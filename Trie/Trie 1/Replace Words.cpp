struct TrieNode{
    TrieNode*childs[26];
    bool isEnd=false;
    bool contain(char ch){
        return (childs[ch-'a']!=nullptr);
    }
    void put(char ch,TrieNode*node){
        childs[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return childs[ch-'a'];
    }
    void setEnd(){
        isEnd=true;
    }
    bool getEnd(){
        return isEnd;
    }
};


class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string&word){
        TrieNode*node=root;
        for(int i=0;i<word.size();++i){
            if(!node->contain(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    string find(string&word){
        TrieNode*node=root;
        string ans="";
        for(int i=0;i<word.size();++i){
            if(node->getEnd()) break;
            if(node->contain(word[i])){
                ans+=word[i];
                node=node->get(word[i]);
            }
            else{
                break;
            }
        }
        if(node->getEnd()){
            return ans;
        }
        else{
            return "";
        }
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        int n=sentence.size();
        int m=dictionary.size();
        string temp="";
        for(int i=0;i<m;++i){
            trie.insert(dictionary[i]);
        }
        string ans="";
        for(int i=0;i<n;++i){
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }
            else{
                string w=trie.find(temp);
                if(w==""){
                    ans+=temp;
                }
                else{
                    ans+=w;
                }
                ans+=' ';
                temp="";
            }
            if(i==n-1){
                string w=trie.find(temp);
                if(w==""){
                    ans+=temp;
                }
                else{
                    ans+=w;
                }
            }
        }
        return ans;
    }
};
