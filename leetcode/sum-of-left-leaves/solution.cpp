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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        int result = 0;
        while(!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            if (node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr) {
                    result += node->left->val;
                }
                else {
                    nodes.push(node->left);
                }
            }
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
        }
        return result;
    }
};
