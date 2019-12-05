class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> nextGreater(nums2.size(), -1);
        std::stack<int> stack;
        stack.push(0);
        
        for (int i = 0; i < nums2.size(); ++i) {
            map[nums2[i]] = i;
            while(!stack.empty() && nums2[i] > nums2[stack.top()]) {
                nextGreater[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(i);
        }
        
        std::vector<int> result(nums1.size(), -1);
        
        for (int i = 0; i < nums1.size(); ++i) {
            result[i] = nextGreater[map[nums1[i]]];
        }
        
        return result;
    }
};
