class Solution {
private:
    void combinationSum(int k, int n, int currentSum, std::vector<int> &candidates, std::vector<std::vector<int>> &result) {
        if (k == 0) {
            if (n == currentSum) {
                result.push_back(candidates);
            }
            return;
        }

        int lastCandidate = candidates.empty() ? 0 : candidates.back();
        for (int i = lastCandidate + 1; i <= std::min(n - currentSum, 9); ++i) {
            candidates.push_back(i);
            currentSum += i;
            combinationSum(k - 1, n, currentSum, candidates, result);
            currentSum -= i;
            candidates.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> candidates;
        std::vector<std::vector<int>> result;
        combinationSum(k, n, 0, candidates, result);

        return result;
    }
};

