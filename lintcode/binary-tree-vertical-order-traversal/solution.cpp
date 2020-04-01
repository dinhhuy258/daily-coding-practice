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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    std::vector<std::vector<int>> verticalOrder(TreeNode * root) {
        if (!root) {
            return {};
        }
        std::unordered_map<int, std::vector<int>> nodesMap;
        std::queue<std::pair<TreeNode*, int>> nodes;
        nodes.push(std::make_pair(root, 0));
        int minLevel = 0;
        while (!nodes.empty()) {
            auto node = nodes.front().first;
            auto level = nodes.front().second;
            nodes.pop();
            if (nodesMap.find(level) == nodesMap.end()) {
                nodesMap[level] = { node->val };
            }
            else {
                nodesMap[level].push_back(node->val);
            }
            if (node->left) {
                minLevel = std::min(minLevel, level - 1);
                nodes.push(std::make_pair(node->left, level - 1));
            }
            if (node->right) {
                nodes.push(std::make_pair(node->right, level + 1));
            }
        }
        
        std::vector<std::vector<int>> result;
        while (nodesMap.find(minLevel) != nodesMap.end()) {
            result.push_back(nodesMap[minLevel++]);
        }
        
        return result;
    }
};
