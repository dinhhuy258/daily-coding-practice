class StreamChecker {
private:
    struct TrieNode {
        TrieNode *children[26];
        bool isEndWord = false;
    };

    void addWord(string word) {
        TrieNode* temp = root;

        for (char c: word) {
            c -=  'a';
            if (!temp->children[c]) {
                temp->children[c] = new TrieNode();
            };
            temp = temp->children[c];
        }
        temp->isEndWord = true;
    }
    TrieNode* root;
    std::vector<TrieNode*> nodes, tempNodes;

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();

        for (auto& word: words) {
            addWord(word);
        }
    }

    bool query(char letter) {
        tempNodes.clear();
        bool result = false;
        nodes.push_back(root);
        auto c = letter -  'a';
        for (int i = 0; i < nodes.size(); ++i) {
            auto& node = nodes[i];
            if (node->children[c]) {
                result |= node->children[c]->isEndWord;
                tempNodes.push_back(node->children[c]);
            }
        }
        nodes = tempNodes;

        return result;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
