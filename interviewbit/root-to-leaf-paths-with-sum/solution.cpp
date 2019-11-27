/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
namespace {
    void pathSumInternal(TreeNode* node, int k, int currentSum, std::vector<int> currentPath, std::vector<std::vector<int>>& result) {
        currentSum += node->val;
        currentPath.push_back(node->val);
        if (!node->left && !node->right && currentSum == k) {
            result.push_back(currentPath);
        }
        if (node->left) {
            pathSumInternal(node->left, k, currentSum, currentPath, result);
        }
        if (node->right) {
            pathSumInternal(node->right, k, currentSum, currentPath, result);
        }
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int k) {
    if (root == nullptr) {
        return {};
    }
    std::vector<std::vector<int>> result;
    pathSumInternal(root, k, 0, {}, result);
    return result;
}
