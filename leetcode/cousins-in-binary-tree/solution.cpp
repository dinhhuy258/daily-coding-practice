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
    bool isCousins(TreeNode* root, int x, int y) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        int nodeRemains = 1;
        bool found = false;
        while(!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            --nodeRemains;
            if (node->val == x || node->val == y) {
                if (found == true) {
                    return true;
                }
                found = true;
            }
            if (node->left && node->right && 
                ((node->left->val == x && node->right->val == y) || 
                 (node->left->val == y && node->right->val == x))) {
                // Two nodes have the same parent
                return false;
            }
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
            if (!nodeRemains) {
                if (found == true) {
                    return false;
                }
                nodeRemains = queue.size();
            }
        }
            
        return false;
    }
};
