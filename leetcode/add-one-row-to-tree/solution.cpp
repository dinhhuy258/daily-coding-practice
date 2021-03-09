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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            auto newRoot = new TreeNode(v);
            newRoot->left = root;

            return newRoot;
        }
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push(std::make_pair(root, 1));
        std::vector<TreeNode*> nodes;
        while (!queue.empty()) {
            auto node = queue.front().first;
            auto level = queue.front().second;
            queue.pop();
            if (level == d - 1) {
                nodes.push_back(node);
            }

            if (node->left && level < d - 1) {
                queue.push(std::make_pair(node->left, level + 1));
            }
            if (node->right && level < d - 1) {
                queue.push(std::make_pair(node->right, level + 1));
            }
        }

        for (auto node: nodes) {
            node->left = new TreeNode(v, node->left, nullptr);
            node->right = new TreeNode(v, nullptr, node->right);
        }

        return root;
    }
};

