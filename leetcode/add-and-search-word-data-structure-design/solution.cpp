class WordDictionary {
private:
    struct TrieNode {
        char value;
        std::array<std::shared_ptr<TrieNode>, 26> children;
        bool isEndWord = false;
    };
    std::shared_ptr<TrieNode> root;
    
    bool search(string word, int i, std::shared_ptr<TrieNode> node) {
        if (i >= word.size()) {
            return node->isEndWord;
        }
        if (word[i] == '.') {
            for (int j = 0; j < node->children.size(); ++j) {
                if (node->children[j]) {
                    if (search(word, i + 1, node->children[j])) {
                        return true;
                    }
                }
            }
            return false;
        }
        if (node->children[word[i] -  'a'] == nullptr) {
            return false;
        }
        return search(word, i + 1, node->children[word[i] -  'a']);
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = std::make_shared<TrieNode>();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        std::shared_ptr<TrieNode> temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (temp->children[word[i] -  'a'] == nullptr) {
                auto child = std::make_shared<TrieNode>();
                child->value = word[i];
                temp->children[word[i] -  'a'] = child;
                temp = child;
            }
            else {
                temp = temp->children[word[i] -  'a'];
            }
        }
        temp->isEndWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
