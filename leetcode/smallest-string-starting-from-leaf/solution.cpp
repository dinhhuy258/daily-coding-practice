/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    std::string toString(int value) {
        return std::string(1, value + 97);
    }
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string result = "";
        if (root == nullptr) {
            return result;
        }
        
        std::stack<std::pair<TreeNode*, std::string>> nodes;
        nodes.push(std::make_pair(root, toString(root->val)));
        while(!nodes.empty()) {
            auto node = nodes.top().first;
            auto currentString = nodes.top().second;
            nodes.pop();
            if (node->left == nullptr && node->right == nullptr && (result.empty() || result > currentString)) {
                result = std::move(currentString);
            }
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, toString(node->left->val) + currentString));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, toString(node->right->val) + currentString));
            }
        }
        
        return result;
    }
};
