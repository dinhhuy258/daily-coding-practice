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
    int diameterOfBinaryTree(TreeNode* root, int &result) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = diameterOfBinaryTree(root->left, result);
        int right = diameterOfBinaryTree(root->right, result);
        result = std::max(result, left + right);
        
        return std::max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        diameterOfBinaryTree(root, result);
        
        return result;
    }
};
