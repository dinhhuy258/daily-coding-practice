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
    std::pair<int /*include root*/, int /*exclude root*/> robInternal(TreeNode* root) {
        if (root == nullptr) {
            return std::make_pair(0, 0);
        }
        auto resultChildLeft = robInternal(root->left);
        auto resultChildRight = robInternal(root->right);
        return std::make_pair(root->val + resultChildLeft.second + resultChildRight.second,
                              std::max(std::max(std::max(resultChildLeft.first + resultChildRight.first, 
                                       resultChildLeft.second + resultChildRight.second),
                                       resultChildLeft.first + resultChildRight.second),
                                       resultChildLeft.second + resultChildRight.first));
    }
public:
    int rob(TreeNode* root) {
        auto robResult = robInternal(root);
        return std::max(robResult.first, robResult.second);   
    }
};
