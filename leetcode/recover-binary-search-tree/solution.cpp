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
public:
    void recoverTree(TreeNode* root) {
        TreeNode *invalidNode1 = nullptr, *invalidNode2 = nullptr;
        std::stack<TreeNode*> stack;
        TreeNode* currentNode = root;
        TreeNode* lastNode = nullptr;
        while (currentNode != nullptr || !stack.empty()) {
            while (currentNode != nullptr) {
                stack.push(currentNode);
                currentNode = currentNode->left;
            }
            currentNode = stack.top();
            stack.pop();
            if (lastNode && lastNode->val > currentNode->val) {
                if (invalidNode1 == nullptr) {
                    invalidNode1 = lastNode;
                    invalidNode2 = currentNode;
                }
                else {
                    invalidNode2 = currentNode;
                }
            }
            lastNode = currentNode;
            currentNode = currentNode->right;
        }
        std::swap(invalidNode1->val, invalidNode2->val);
    }
};
