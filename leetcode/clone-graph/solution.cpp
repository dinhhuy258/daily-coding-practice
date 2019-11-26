/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        std::vector<Node*> visited(101 /* The number of nodes will be between 1 and 100 */, nullptr);
        std::stack<Node*> nodes;
        nodes.push(node);
        auto cloneNode = new Node(node->val, std::vector<Node*>{});
        visited[node->val] = cloneNode;
        while(!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            for (auto& neighbor: node->neighbors) {
                if (visited[neighbor->val] == nullptr) {
                    auto cloneNeighbor = new Node(neighbor->val, std::vector<Node*>{});
                    visited[neighbor->val] = cloneNeighbor;
                    nodes.push(neighbor);
                }
                visited[node->val]->neighbors.push_back(visited[neighbor->val]);
            }
        }
        return cloneNode;
    }
};
