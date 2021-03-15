class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        std::unordered_map<int, long> map;
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            long count = 1;
            for (int j = 0; j <= i; ++j) {
                if (arr[i] % arr[j] == 0 && map.find(arr[i] / arr[j]) != map.end()) {
                    count += map[arr[i] / arr[j]] * map[arr[j]];
                }
            }
            map[arr[i]] = count;
        }
        long ans = 0;
        for (auto &iter: map) {
            ans += iter.second;
            ans %= 1000000007;
        }

        return ans;
    }
};

