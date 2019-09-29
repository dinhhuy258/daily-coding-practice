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
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<std::pair<TreeNode*, int>> nodes;
        nodes.push(std::make_pair(root, root->val));
        int result = 0;
        while(!nodes.empty()) {
            auto node = nodes.front().first;
            auto currentNumber = nodes.front().second;
            nodes.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result += currentNumber;
            }
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node->left, currentNumber * 10 + node->left->val));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node->right, currentNumber * 10 + node->right->val));
            }
        }
        return result;
    }
};