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
    int pathSum(TreeNode* root, int currentSum, int sum, bool startNode) {
        if (root == nullptr) {
            return 0;
        }

        return (currentSum + root->val == sum ? 1 : 0) + 
            pathSum(root->left, currentSum + root->val, sum, false) + 
            pathSum(root->right, currentSum + root->val, sum, false) + 
            (startNode ? (pathSum(root->left, 0, sum, true) + pathSum(root->right, 0, sum, true)) : 0);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        return pathSum(root, 0, sum, true);
    }
};
