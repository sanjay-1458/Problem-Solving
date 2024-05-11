bool comparePairs(pair<int, string> &p1, pair<int, string> &p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}  

class Trie {
    Trie* children[27];
    unordered_map<string, int> wordFrequencyMap;
    
public:
    Trie(): children{nullptr} {}
    
    void insert(string &word, int frequency) {
        Trie *node = this;
        for (int i=0; i<word.length(); i++) {
            int index = word[i]-'a';
            if (index == -65) index = 26;
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
            node->wordFrequencyMap[word] += frequency;
        }
    }
    
    Trie* search(char &character, vector<pair<int, string>> &suggestions) {
        Trie *node = this;
        int index = character-'a';
        if (index == -65) index = 26;
        if (node->children[index] == nullptr) {
            return nullptr;
        }
        node = node->children[index];
        
        for (auto &entry: node->wordFrequencyMap) {
            suggestions.push_back({entry.second, entry.first});
        }
        
        sort(suggestions.begin(), suggestions.end(), comparePairs);
        return node;
    }
};

class AutoCompleteSystem {
    Trie* root;
    string currentInput;
    Trie *currentCharacter;
    
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new Trie();
        currentCharacter = root;
        for (int i=0; i<sentences.size(); i++) {
            root->insert(sentences[i], times[i]);
        }
    }
    vector<string> input(char c) {
        if (c == '#') {
            root->insert(currentInput, 1);
            currentInput = "";
            currentCharacter = root; 
            return {};
        }
        currentInput += c;
        
        
        vector<pair<int, string>> suggestions;
        vector<string> result;
        if (currentCharacter == nullptr) {
            return result;
        }
        
        currentCharacter = currentCharacter->search(c, suggestions);

        for (int i=0, j=0; i<3 && j<suggestions.size(); i++, j++) {
            result.push_back(suggestions[i].second);
        }
        return result;
    }
};


/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
