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
    int longestUnivaluePath(TreeNode* root, int *ans) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = longestUnivaluePath(root->left, ans);
        int right = longestUnivaluePath(root->right, ans);
        left = (root->left && root->left->val == root->val) ? left + 1 : 0;
        right = (root->right && root->right->val == root->val) ? right + 1 : 0;
        *ans = std::max(*ans, left + right);
        
        return std::max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {     
        int ans = 0;
        longestUnivaluePath(root, &ans);
        return ans;
    }
};
