#define MODULE 1000000007

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
    int createSortedArray(std::vector<int>& instructions) {
        int ans = 0;
        FenwickTree fenwickTree(*(std::max_element(instructions.begin(), instructions.end())) + 1);
        for (int i = 0; i < instructions.size(); ++i) {
            auto numLess = fenwickTree.query(instructions[i] - 1);
            auto numGreater = i - fenwickTree.query(instructions[i]);
            ans += std::min(numLess, numGreater);
            ans = ans % MODULE;
            fenwickTree.update(instructions[i]);
        }

        return ans;
    }
};

