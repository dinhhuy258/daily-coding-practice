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
private:
    int findTilt(TreeNode* root, int &result) {
        if (root == nullptr) {
            return 0;
        }

        int left = findTilt(root->left, result);
        int right = findTilt(root->right, result);
        result += std::abs(left - right);

        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        findTilt(root, result);
        return result;
    }
};

