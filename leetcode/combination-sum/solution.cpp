class Solution {
private:
    void combinationSum(std::vector<int>& candidates,
                        int startIndex,
                        int remaining, 
                        std::vector<int>& subResult,
                        std::vector<std::vector<int>>& result) {
        if (candidates.empty() || remaining < 0) {
            return;
        }
        if (remaining == 0) {
            result.push_back(std::vector<int>(subResult.begin(), subResult.end()));
            return;
        }
        for (int i = startIndex; i < candidates.size(); ++i) {
            subResult.push_back(candidates[i]);
            combinationSum(candidates, i, remaining - candidates[i], subResult, result);
            subResult.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> subResult;
        combinationSum(candidates, 0, target, subResult, result);
        return result;
    }
};