class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), -1);
        std::stack<int> stack;
        for (int i = 0; i < nums.size(); ++i) {
            while(!stack.empty() && nums[stack.top()] < nums[i]) {
                result[stack.top()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            while(!stack.empty() && nums[stack.top()] < nums[i]) {
                result[stack.top()] = nums[i];
                stack.pop();
            }
        }
        
        return result;
    }
};
