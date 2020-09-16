class Solution {
private:
    struct TrieNode {
        TrieNode *children[2];
    };
    void addNumber(int number) {
        TrieNode* current = root;

        for (int i = 31; i >= 0; --i) {
            int value = int(((1 << i) & number) != 0);
            if (current->children[value] == nullptr) {
                current->children[value] = new TrieNode();
            }
            current = current->children[value];
        }
    }

    TrieNode* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();

        for (auto& num: nums) {
            addNumber(num);
        }

        int ans = 0;

        for (auto& num: nums) {
            TrieNode* current = root;
            int currentXor = 0;
            for (int i = 31; i >= 0; --i) {
                int value = int(((1 << i) & num) != 0);
                if (value) {
                    // 1
                    if (current->children[0] != nullptr) {
                        current = current->children[0];
                        currentXor |= (1 << i);
                    }
                    else {
                        current = current->children[1];
                    }
                }
                else {
                    // 0
                    if (current->children[1] != nullptr) {
                        current = current->children[1];
                        currentXor |= (1 << i);
                    }
                    else {
                        current = current->children[0];
                    }
                }
            }
            ans = std::max(currentXor, ans);
        }

        return ans;
    }
};

