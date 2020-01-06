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
private:
    /**
     * @param root: the root of binary tree
     * @param consecutiveSequenceLength: the current consecutive sequence length
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root, int consecutiveSequenceLength) {
        int result = consecutiveSequenceLength;
        if (root->left) {
            result = std::max(result, longestConsecutive(root->left, root->left->val == root->val + 1 ? consecutiveSequenceLength + 1 : 1));
        }
        if (root->right) {
            result = std::max(result, longestConsecutive(root->right, root->right->val == root->val + 1 ? consecutiveSequenceLength + 1 : 1));
        }
        
        return result;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        if (root == nullptr) {
            return 0;
        }
        
        return longestConsecutive(root, 1);
    }
};
