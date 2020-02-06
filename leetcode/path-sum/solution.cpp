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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }
        std::stack<std::pair<TreeNode*, int>> nodes;
        nodes.push(std::make_pair(root, root->val));
        
        while(!nodes.empty()) {
            auto node = nodes.top().first;
            auto currentSum = nodes.top().second;
            nodes.pop();
            if (node->left == nullptr && node->right == nullptr && currentSum == sum) {
                return true;
            }
            if (node->left) {
                nodes.push(std::make_pair(node->left, currentSum + node->left->val));
            }
            if (node->right) {
                nodes.push(std::make_pair(node->right, currentSum + node->right->val));
            }
        }
        return false;
    }
};
