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
        return root != nullptr &&
            ((root->left == nullptr && root->right == nullptr && sum - root->val == 0) || 
            hasPathSum(root->left, sum - root->val) || 
            hasPathSum(root->right, sum - root->val));
    }
};
