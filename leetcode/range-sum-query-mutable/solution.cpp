class NumArray {
private:
    std::vector<int> elements;
    std::vector<int> nodes;

public:
    NumArray(std::vector<int>& nums) {
        nodes.resize(nums.size() + 1);
        elements.resize(nums.size());
        std::fill(nodes.begin(), nodes.end(), 0);
        std::fill(elements.begin(), elements.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int delta = val - elements[i];
        elements[i] = val;
        ++i;
        for (; i < nodes.size(); i += i & -i) {
            nodes[i] += delta;
        }
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }

private:
    int sum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += nodes[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */