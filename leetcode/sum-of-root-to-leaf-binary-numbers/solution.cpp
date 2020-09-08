/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push(std::make_pair(root, 0));
        int sum = 0;
        int currentNumber = 0;
        while (!stack.empty()) {
            auto node = stack.top().first;
            auto number = stack.top().second;
            stack.pop();
            number <<= 1;
            number |= node->val;
            if (node->left == nullptr && node->right == nullptr) {
                sum += number;
            }
            if (node->left) {
                stack.push(std::make_pair(node->left, number));
            }
            if (node->right) {
                stack.push(std::make_pair(node->right, number));
            }
        }

        return sum;
    }
};

