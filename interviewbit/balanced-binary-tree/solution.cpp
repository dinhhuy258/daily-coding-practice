/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isBalancedInternal(TreeNode* A) {
    if (A == nullptr) {
        return 1;
    }
    int leftHeight = isBalancedInternal(A->left);
    if (leftHeight == 0) {
        return 0;
    }
    int rightHeight = isBalancedInternal(A->right);
    if (rightHeight == 0) {
        return 0;
    }
    if (std::abs(leftHeight - rightHeight) > 1) {
        return 0;
    }
    return 1 + std::max(leftHeight, rightHeight);
}

int Solution::isBalanced(TreeNode* A) {
    return isBalancedInternal(A) == 0 ? 0 : 1;
}
