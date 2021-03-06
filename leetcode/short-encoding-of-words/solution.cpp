class Solution {
private:
    struct TrieNode {
        TrieNode *children[26];
    };

    void addWord(string word) {
        TrieNode* temp = root;

        for (int i = word.size() - 1; i >= 0; --i) {
            auto c = word[i];
            c -=  'a';
            if (!temp->children[c]) {
                temp->children[c] = new TrieNode();
            };
            temp = temp->children[c];
        }
    }

    bool search(string word) {
        TrieNode* temp = root;
        for (int i = word.size() - 1; i >= 0; --i) {
            auto c = word[i];
            c -= 'a';
            if (temp->children[c] == nullptr) {
                return false;
            }
            temp = temp->children[c];
        }

        return true;
    }

    TrieNode* root = nullptr;
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        sort(words.begin(), words.end(), [](string &a,string &b){
            return a.length() > b.length();
        });
        for (auto& word: words) {
            if (root == nullptr) {
                root = new TrieNode();
                ans += word.size() + 1; /* plus 1 for # character in the end */
                addWord(word);
            }
            else if (!search(word)) {
                ans += word.size() + 1; /* plus 1 for # character in the end */
                addWord(word);
            }
        }

        return ans;
    }
};
