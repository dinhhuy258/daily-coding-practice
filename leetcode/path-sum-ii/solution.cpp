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
    void pathSum(TreeNode* root, int sum, std::vector<int> currentPath, std::vector<std::vector<int>> &result) {
        if (root == nullptr) {
            return;
        }
        currentPath.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum - root->val == 0) {
            result.push_back(currentPath);
        }
        pathSum(root->left, sum - root->val, currentPath, result);
        pathSum(root->right, sum - root->val, currentPath, result);
        currentPath.pop_back();
    }
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> result;
        pathSum(root, sum, {}, result);
        
        return result;
    }
};
