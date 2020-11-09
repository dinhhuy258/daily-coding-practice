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
    int maxAncestorDiff(TreeNode* root) {
        std::stack<std::tuple<TreeNode*, int, int>> nodes;
        nodes.push(std::make_tuple(root, root->val, root->val));
        TreeNode* node;
        int currentMin, currentMax;
        int ans = 0;
        while (!nodes.empty()) {
            std::tie(node, currentMin, currentMax) = nodes.top();
            nodes.pop();
            if (node->left) {
                ans = std::max(std::abs(node->left->val - currentMin), ans);
                ans = std::max(std::abs(node->left->val - currentMax), ans);
                nodes.push(std::make_tuple(node->left, std::min(currentMin, node->left->val), std::max(currentMax, node->left->val)));
            }
            if (node->right) {
                ans = std::max(std::abs(node->right->val - currentMin), ans);
                ans = std::max(std::abs(node->right->val - currentMax), ans);
                nodes.push(std::make_tuple(node->right, std::min(currentMin, node->right->val), std::max(currentMax, node->right->val)));
            }
        }

        return ans;
    }
};

