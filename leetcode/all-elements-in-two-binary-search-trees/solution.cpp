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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::stack<TreeNode*> stack1, stack2;
        TreeNode *currentNode1 = root1;
        TreeNode *currentNode2 = root2;
        std::vector<int> elements;
        while (true) {
            while (currentNode1 != nullptr) {
                stack1.push(currentNode1);
                currentNode1 = currentNode1->left;
            }
            while (currentNode2 != nullptr) {
                stack2.push(currentNode2);
                currentNode2 = currentNode2->left;
            }

            if (stack1.empty() && stack2.empty()) {
                break;
            }
            else if (!stack1.empty() && stack2.empty() || (!stack1.empty() && !stack2.empty() && stack1.top()->val <= stack2.top()->val)) {
                elements.push_back(stack1.top()->val);
                currentNode1 = stack1.top()->right;
                stack1.pop();
            }
            else if (stack1.empty() && !stack2.empty() || (!stack1.empty() && !stack2.empty() && stack1.top()->val > stack2.top()->val)) {
                elements.push_back(stack2.top()->val);
                currentNode2 = stack2.top()->right;
                stack2.pop();
            }
        }

        return elements;
    }
};

