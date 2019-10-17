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
    int findSum(TreeNode* root, std::unordered_map<int, int>& frequent) {
        int leftSum = 0;
        int rightSum = 0;
        if (root->left) {
            leftSum = findSum(root->left, frequent);
            ++frequent[leftSum];
        }
        if (root->right) {
            rightSum = findSum(root->right, frequent);
            ++frequent[rightSum];
        }
        return root->val + leftSum + rightSum;
    }
public:
    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }
        std::unordered_map<int, int> frequent;
        ++frequent[findSum(root, frequent)];
        int max =  std::numeric_limits<int>::min();
        for (auto& frequentIter: frequent) {
            if (frequentIter.second > max) {
                max = frequentIter.second;
            }
        }
        for (auto& frequentIter: frequent) {
            if (frequentIter.second == max) {
                result.push_back(frequentIter.first);
            }
        }
        return result;
    }
};
