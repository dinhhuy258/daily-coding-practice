class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());

        int n = citations.size();
        int hIndexValue = 0;
        for (int i = 0; i < n; ++i) {
            hIndexValue = std::max(hIndexValue, std::min(citations[i], n - i));
        }

        return hIndexValue;
    }
};

