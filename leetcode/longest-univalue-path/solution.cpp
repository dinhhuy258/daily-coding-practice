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
    int longestUnivaluePath(TreeNode* root, int currentUnivaluePath) {
        int left = root->left != nullptr && root->left->val == root->val ? 
            longestUnivaluePath(root->left, currentUnivaluePath + 1) : currentUnivaluePath;
        int right = root->right != nullptr && root->right->val == root->val ? 
            longestUnivaluePath(root->right, currentUnivaluePath + 1) : currentUnivaluePath;

        return std::max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int result = 0;
        if (root->left && root->left->val == root->val) {
            result += longestUnivaluePath(root->left, 1);
        }
        if (root->right && root->right->val == root->val) {
            result += longestUnivaluePath(root->right, 1);
        }
        return std::max(std::max(result, 
                                 longestUnivaluePath(root->left)), 
                                 longestUnivaluePath(root->right));
    }
};
