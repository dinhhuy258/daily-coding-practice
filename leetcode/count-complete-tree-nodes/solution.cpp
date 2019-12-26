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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return height(root->left) + 1;
    }
    int countMissingNodes(TreeNode* root, int currentHeight, int height) {
        if (root == nullptr || currentHeight >= height) {
            return 0;
        }
        if (currentHeight != height - 1) {
            return countMissingNodes(root->left, currentHeight + 1, height) + countMissingNodes(root->right, currentHeight + 1, height);
        }
        if (root->left == nullptr) {
            return 2;
        }
        if (root->right == nullptr) {
            return 1;
        }
        return 0;
    }
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        int ans = std::pow(2, h) - 1;
        ans -= countMissingNodes(root, 1, h);
        return ans;
    }
};
