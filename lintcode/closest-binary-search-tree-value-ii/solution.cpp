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
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    std::vector<int> closestKValues(TreeNode * root, double target, int k) {
        std::queue<int> upperValues;
        std::stack<int> lowerValues;
        std::stack<TreeNode*> stack;
        TreeNode* currentNode = root;
        
        // Inorder traversal
        while(currentNode != nullptr || !stack.empty()) {
            while (currentNode != nullptr) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }
            auto value = stack.top()->val;
            if (value > target) {
                upperValues.push(value);
            }
            else {
                lowerValues.push(value);
            }
            currentNode = stack.top()->right;
            stack.pop();
        }
        
        std::vector<int> ans(k, 0);
        for (int i = k - 1; i >= 0; --i) {
            if (lowerValues.empty()) {
                ans[i] = upperValues.front();
                upperValues.pop();
            }
            else if (upperValues.empty()) {
                ans[i] = lowerValues.top();
                lowerValues.pop();
            }
            else if (std::abs(lowerValues.top() - target) <= std::abs(upperValues.front() - target)) {
                ans[i] = lowerValues.top();
                lowerValues.pop();        
            }
            else {
                ans[i] = upperValues.front();
                upperValues.pop();
            }
        }
        return ans;
    }
};
