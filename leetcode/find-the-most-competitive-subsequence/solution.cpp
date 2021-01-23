class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int x = n - k;
        std::deque<int> queue;
        for (int i = 0; i < n; ++i) {
            while (!queue.empty() && queue.back() > nums[i] && x-- > 0) {
                queue.pop_back();
            }
            queue.push_back(nums[i]);
        }

        return { queue.begin(), queue.begin() + k };
    }
};

