/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    std::pair<TreeNode*, TreeNode*> findNode(TreeNode* parent, TreeNode* root, int key) {
        if (root == nullptr || root->val == key) {
            return std::make_pair(parent, root);
        }

        return findNode(root, root->val < key ? root->right : root->left, key);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto foundNode = findNode(nullptr, root, key);
        auto parent = foundNode.first;
        auto deleteNode = foundNode.second;
        if (deleteNode == nullptr) {
            return root;
        }
        auto right = deleteNode->right;
        auto left = deleteNode->left;

        if (right != nullptr) {
            auto temp = right;
            while(temp->left != nullptr) {
                temp = temp->left;
            }
            temp->left = left;
        }
        if (parent == nullptr) {
            return right == nullptr ? left : right;
        }

        if (parent->left == deleteNode) {
            parent->left = right == nullptr ? left : right;
        }
        else if (parent->right == deleteNode) {
            parent->right = right == nullptr ? left :  right;
        }

        return root;
    }
};

