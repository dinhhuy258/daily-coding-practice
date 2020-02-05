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
    void binaryTreePaths(TreeNode* root,
                         std::string currentPath,
                         std::vector<std::string>& paths) {
        currentPath += std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(currentPath);
            return;
        }
        if (root->left) {
            binaryTreePaths(root->left, currentPath + "->", paths);
        }
        if (root->right) {
            binaryTreePaths(root->right, currentPath + "->", paths);
        }
    }
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::string> paths;
        binaryTreePaths(root, "", paths);
        
        return paths;
    }
};