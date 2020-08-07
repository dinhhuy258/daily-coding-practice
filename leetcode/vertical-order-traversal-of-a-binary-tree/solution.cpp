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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::unordered_map<int, std::vector<std::pair<int, int>>> nodesMap;
        std::queue<std::pair<TreeNode*, std::pair<int, int>>> nodes;
        nodes.push(std::make_pair(root, std::make_pair(0, 0)));
        int minLevel = 0;
        while (!nodes.empty()) {
            auto node = nodes.front().first;
            auto level = nodes.front().second.first;
            auto depth = nodes.front().second.second;

            nodes.pop();
            if (nodesMap.find(level) == nodesMap.end()) {
                nodesMap[level] = { std::make_pair(node->val, depth) };
            }
            else {
                std::vector<std::pair<int, int>> values;
                while(!nodesMap[level].empty() && nodesMap[level].back().second == depth && nodesMap[level].back().first > node->val) {
                    values.push_back(nodesMap[level].back());
                    nodesMap[level].pop_back();
                }
                nodesMap[level].push_back(std::make_pair(node->val, depth));

                for (int i = values.size() - 1; i >= 0; --i) {
                    nodesMap[level].push_back(values[i]);
                }
            }
            if (node->left) {
                minLevel = std::min(minLevel, level - 1);
                nodes.push(std::make_pair(node->left, std::make_pair(level - 1, depth + 1)));
            }
            if (node->right) {
                nodes.push(std::make_pair(node->right, std::make_pair(level + 1, depth + 1)));
            }
        }

        std::vector<std::vector<int>> result;
        while (nodesMap.find(minLevel) != nodesMap.end()) {
            auto nodes = nodesMap[minLevel++];
            std::vector<int> values;
            for (auto& node: nodes) {
                values.push_back(node.first);
            }
            result.push_back(values);
        }

        return result;
    }
};

