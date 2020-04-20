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
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        std::stack<TreeNode*> stack;
        stack.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            if (stack.empty()) {
                stack.push(node);
            }
            else if (stack.top()->val > node->val) {
                stack.top()->left = node;
                stack.push(node);
            }
            else {
                TreeNode* tempNode = nullptr;
                while (!stack.empty() && stack.top()->val < node->val) {
                    tempNode = stack.top();
                    stack.pop();
                }
                tempNode->right = node;
                stack.push(node);
            }
        }
        return root;
    }
};
