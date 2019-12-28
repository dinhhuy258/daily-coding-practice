/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        double ans = root->val;
        while(root != nullptr) {
            if (std::abs(target - root->val) < std::abs(target - ans)) {
                ans = root->val;
            }
            if (root->val == target || 
            (root->val > target && root->val < ans) || 
            (root->val < target && root->val > ans)) {
                break;
            }
            root = root->val > target ? root->left : root->right;
        }
        
        return ans;
    }
};
