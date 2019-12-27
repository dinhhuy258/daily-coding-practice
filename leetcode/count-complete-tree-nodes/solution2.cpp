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
    int height(TreeNode* root, bool goLeft = true) {
        if (root == nullptr) {
            return 0;
        }
        return (goLeft ? height(root->left, goLeft) : height(root->right, goLeft)) + 1;
    }
  
    int countLeafNodes(TreeNode* root, int maxHeight) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int currentMaxHeight = maxHeight - 1;
        int ans = 0;
        while(currentMaxHeight > 0) {
            int h = height(left, false);
            if (h == currentMaxHeight) {
                ans += std::pow(2, currentMaxHeight) / 2;
                if (right != nullptr) {
                    left = right->left;
                    right = right->right; 
                }
            }
            else {
                if (left != nullptr) { 
                    right = left->right;
                    left = left->left;
                }
            }
            --currentMaxHeight;
        }
        return ans;
    }
    
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == height(root, false)) {
            // full binary tree
            return std::pow(2, h) - 1;
        }
        int ans = std::pow(2, h - 1) - 1;
        ans += countLeafNodes(root, h);
        return ans;
    }
};
