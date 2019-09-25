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
    std::vector<TreeNode*> delNode(std::vector<TreeNode*>& roots, int toDelete) {
        std::vector<TreeNode*> forest;
        for (int i = 0; i < roots.size(); ++i) {
            std::vector<TreeNode*> remainingForest = delNode(roots[i], toDelete);
            for (int j = 0; j < remainingForest.size(); ++j) {
                forest.push_back(remainingForest[j]);
            }
        }
        return forest;
    }
    std::vector<TreeNode*> delNode(TreeNode* root, int toDelete) {
        std::stack<std::pair<TreeNode*, TreeNode*>> nodes;
        std::vector<TreeNode*> forest;
        nodes.push(std::make_pair(nullptr, root));
        while(!nodes.empty()) {
            TreeNode* parent = nodes.top().first;
            TreeNode* node = nodes.top().second;
            nodes.pop();
            if (node->val == toDelete) {
                if (node->left != nullptr) {
                    forest.push_back(node->left);
                }
                if (node->right != nullptr) {
                    forest.push_back(node->right);
                }
                if (parent != nullptr) {
                    if (parent->right == node) {
                        parent->right = nullptr;
                    }
                    else {
                        parent->left = nullptr;
                    }
                    forest.push_back(root);
                }
                return forest;
            }
            if (node->left != nullptr) {
                nodes.push(std::make_pair(node, node->left));
            }
            if (node->right != nullptr) {
                nodes.push(std::make_pair(node, node->right));
            }
        }
        forest.push_back(root);
        return forest;
    }
public:
    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& toDeletes) {
        std::vector<TreeNode*> forest;
        if (root == nullptr) {
            return forest;
        }
        forest.push_back(root);
        for (int i = 0; i < toDeletes.size(); ++i) {
           forest = delNode(forest, toDeletes[i]);
        }
        return forest;
    }
};