class Solution {
private:
    int _find(int node, std::vector<int>& parents) {
        while (parents[node] != node) {
            node = parents[node];
        }

        return node;
    }
    void _union(int nodeA, int nodeB, std::vector<int>& parents) {
        int parentA = _find(nodeA, parents);
        int parentB = _find(nodeB, parents);
        if (parentA < parentB) {
            parents[parentB] = parentA;
        }
        else {
            parents[parentA] = parentB;
        }

    }
public:
    int largestComponentSize(std::vector<int>& A) {
        int maxValue = *std::max_element(A.begin(), A.end());
        std::vector<int> parents(maxValue + 1, 0);
        for (int i = 0; i <= maxValue; ++i) {
            parents[i] = i;
        }
        for (auto& value: A) {
            for (int i = 2; i * i <= value; ++i) {
                if (value % i == 0) {
                    _union(value, i, parents);
                    _union(value, value / i, parents);
                }
            }
        }

        std::unordered_map<int, int> freq;
        int max = 1;
        for (auto& value : A) {
            max = std::max(max, ++freq[_find(value, parents)]);
        }

        return max;
    }
};

