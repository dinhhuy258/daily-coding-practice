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
     TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
         if (left > right) {
             return nullptr;
         }
         if (left == right) {
             return new TreeNode(nums[left]);
         }
         // Find maxinum index
         int maxIndex = left;
         for (int i = left + 1; i <= right; ++i) {
             if (nums[i] > nums[maxIndex]) {
                 maxIndex = i;
             }
         }
         TreeNode *root = new TreeNode(nums[maxIndex]);
         root->left = constructMaximumBinaryTree(nums, left, maxIndex - 1);
         root->right = constructMaximumBinaryTree(nums, maxIndex + 1, right);

         return root;
     }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};

