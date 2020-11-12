class Solution {
private:
    void permuteUnique(std::vector<int>& counter, int maxSize, std::vector<int>&currentAns, std::vector<std::vector<int>>&ans) {
        if (maxSize == currentAns.size()) {
            ans.push_back(currentAns);
            return;
        }
        for (int i = 0; i <= 20; ++i) {
            if (counter[i] == 0) {
                continue;
            }
            --counter[i];
            currentAns.push_back(i - 10);
            permuteUnique(counter, maxSize, currentAns, ans);
            currentAns.pop_back();
            ++counter[i];
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<int> counter = std::vector<int>(21, 0);
        for (auto& num: nums) {
            ++counter[num + 10];
        }
        std::vector<std::vector<int>> ans;
        std::vector<int> currentAns;
        permuteUnique(counter, nums.size(), currentAns, ans);

        return ans;
    }
};

