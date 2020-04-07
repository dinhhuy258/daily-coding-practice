class Solution {
public:
    int countElements(std::vector<int>& arr) {
        int counter[1001];
        bool exist[1001];
        std::fill(std::begin(counter), std::end(counter), 0);
        std::fill(std::begin(exist), std::end(exist), false);
        int result = 0;
        for (auto& num: arr) {
            ++counter[num];
            exist[num] = true;
            if (num != 0 && counter[num - 1] != 0) {
                result += counter[num - 1];
                counter[num - 1] = 0;
            }
            if (num != 1000 && exist[num + 1]) {
                ++result;
                --counter[num];
            }
        }
        
        return result;
    }
};
