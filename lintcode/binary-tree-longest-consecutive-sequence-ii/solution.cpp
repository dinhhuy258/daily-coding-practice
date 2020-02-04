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
     * @return: the longest increasing sequence and the longest decreasing sequence in pair
     */
    std::pair<int /*longest increasing sequence*/, int /*longest decreasing sequence*/> 
    longestConsecutive2(TreeNode * root, int& consecutiveSequenceLength) {
        if (root == nullptr) {
            return std::make_pair(0, 0);
        }
        auto longestConsecutiveLeft = longestConsecutive2(root->left, consecutiveSequenceLength);
        auto longestConsecutiveRight = longestConsecutive2(root->right, consecutiveSequenceLength);
        int longestIncreasingSequence = 0;
        int longestDecreasingSequence = 0;
        if (root->left != nullptr) {
            if (root->val == root->left->val + 1) {
                // Increasing
                longestIncreasingSequence = longestConsecutiveLeft.first + 1;
            }
            else if (root->val == root->left->val - 1) {
                // Decreasing
                longestDecreasingSequence = longestConsecutiveLeft.second + 1;
            }
        }
        if (root->right != nullptr) {
            if (root->val == root->right->val + 1) {
                // Increasing
                longestIncreasingSequence = std::max(longestIncreasingSequence, longestConsecutiveRight.first + 1);
            }
            else if (root->val == root->right->val - 1) {
                // Decreasing
                longestDecreasingSequence = std::max(longestDecreasingSequence, longestConsecutiveRight.second + 1);
            } 
        }
        consecutiveSequenceLength = std::max(consecutiveSequenceLength, longestIncreasingSequence + longestDecreasingSequence + 1);
        
        return std::make_pair(longestIncreasingSequence,longestDecreasingSequence);
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        int result = 0;
        longestConsecutive2(root, result);
        
        return result;
    }
};
