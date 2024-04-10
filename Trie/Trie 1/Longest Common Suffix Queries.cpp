struct TrieNode{
    TrieNode *childs[26];
    int length;
    int index;
    TrieNode(){
        for(int i=0;i<26;++i){
            childs[i]=nullptr;
            length=(int)1e5;
            index=(int)1e5;
        }
    }
    bool contain(char ch){
        return (childs[ch-'a']!=nullptr);
    }
    void put(char ch,TrieNode*node){
        childs[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return childs[ch-'a'];
    }
    void setLengthIndex(char ch,int size,int pos){
        int item=ch-'a';
        if(length>size){
            length=size;
            index=pos;
        }
        else if(length==size){
            index=min(index,pos);
        }
        // cout<<index[item]<<" "<<ch<<" "<<length[item]<<endl;
    }
    int getIndex(char ch){
        return index;
    }
};


class Trie{
private:
    TrieNode*root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string &word,int index){
        TrieNode* node=root;
        for(int i=0;i<word.size();++i){
            if(!node->contain(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
            node->setLengthIndex(word[i],word.size(),index);
        }
        
    }
    int find(string &word){
        TrieNode*node=root;
        int ans=-1;
        for(int i=0;i<word.size();++i){
            if(node->contain(word[i])){
                node=node->get(word[i]);
                ans=node->getIndex(word[i]);
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
    vector<int> stringIndices(vector<string>& cont, vector<string>& query) {
        Trie trie;
        int n=cont.size(),m=query.size();
        vector<int> ans(m);
        int minLen=(int)1e5;
        int pos=(int)1e5;
        for(int i=0;i<n;++i){
            // string w=cont[i];
            reverse(cont[i].begin(),cont[i].end());
            trie.insert(cont[i],i);
            if(minLen>cont[i].size()){
                minLen=cont[i].size();
                pos=i;
            }
            else if(minLen==cont[i].size()){
                pos=min(pos,i);
            }
        }
        for(int i=0;i<m;++i){
            // string w=query[i];
            reverse(query[i].begin(),query[i].end());
            int x=trie.find(query[i]);
            if(x==-1) ans[i]=pos;
            else ans[i]=x;
        }
        return ans;
    }
};
