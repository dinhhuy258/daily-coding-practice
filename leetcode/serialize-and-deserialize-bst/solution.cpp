/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode* deserialize(std::queue<int>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(nodes.front());
        nodes.pop();

        std::queue<int> leftNodes;
        while (!nodes.empty() && nodes.front() < root->val) {
            leftNodes.push(nodes.front());
            nodes.pop();
        }

        root->left = deserialize(leftNodes);
        root->right = deserialize(nodes);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        return std::to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // First split the data
        istringstream ss(data);
        std::queue<int> nodes;
        while (ss) {
            std::string node;
            ss >> node;
            if (node == "") {
                break;
            }
            nodes.push(stoi(node));
        }

        return deserialize(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

