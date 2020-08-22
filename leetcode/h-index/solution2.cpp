class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::vector<int> citationsCount(citations.size() + 1, 0);
        int size = citations.size();
        int result = 0;
        for (int i = 0; i < size; ++i) {
            auto value = citations[i] > size ? size : citations[i];
            ++citationsCount[value];
        }

        for (int i = 1; i <= size; ++i) {
            citationsCount[i] += citationsCount[i - 1];
        }

        for (int i = 0; i < size; ++i) {
            auto value = citations[i] > size ? size : citations[i];
            result = std::max(result, std::min(value, size - citationsCount[value] + 1));
            --citationsCount[value];
        }

        return result;
    }
};

