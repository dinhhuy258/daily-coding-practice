class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequent;
        for (int i = 0; i < nums.size(); ++i) {
            if (frequent.find(nums[i]) == frequent.end()) {
                frequent[nums[i]] = 1;
            }
            else {
                ++frequent[nums[i]];
            }
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> topFrequent;
        for(auto iter = frequent.begin(); iter != frequent.end(); ++iter) {
            topFrequent.push(std::make_pair(iter->second, iter->first));
            if (topFrequent.size() > k) {
                topFrequent.pop();
            }
        }
        std::vector<int> topKFrequentElements(k, 0);
        int index = k - 1;
        while(!topFrequent.empty()) {
            topKFrequentElements[index--] = topFrequent.top().second;
            topFrequent.pop();
        }
        return topKFrequentElements;

    }
};
