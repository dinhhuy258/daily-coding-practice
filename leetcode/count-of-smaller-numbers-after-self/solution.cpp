class FenwickTree {
private:
    std::vector<int> nodes;

public:
    FenwickTree(int size): nodes(size + 1, 0) {
    }

    void update(int i) {
        for (; i < nodes.size(); i += i & -i) {
            nodes[i] += 1;
        }
    }

    int query(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += nodes[i];
        }
        return result;
    }
};

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        std::vector<int> result = nums;
        std::sort(result.begin(), result.end());
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = std::lower_bound(result.begin(), result.end(), nums[i]) - result.begin() + 1;
        }
        std::fill(result.begin(), result.end(), 0);
        FenwickTree fenwickTree(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] = fenwickTree.query(nums[i] - 1);
            fenwickTree.update(nums[i]);
        }
        return result;
    }
};
