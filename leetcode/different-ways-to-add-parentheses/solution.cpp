class Solution {
private:
    bool isNumber(std::string &input) {
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                return false;
            }
        }

        return true;
    }

    std::vector<int> diffWaysToCompute(std::string input, std::unordered_map<std::string, std::vector<int>> &cache) {
        if (cache.find(input) != cache.end()) {
            return cache[input];
        }
        std::vector<int> result;
        if (isNumber(input)) {
            result.push_back(std::stoi(input));
            return result;
        }

        for (int index = 0; index < input.size(); ++index) {
            if (input[index] == '+' || input[index] == '-' || input[index] == '*') {
                auto leftResult = diffWaysToCompute(input.substr(0, index), cache);
                auto rightResult = diffWaysToCompute(input.substr(index + 1), cache);
                for (int i = 0 ; i < leftResult.size(); ++i) {
                    for (int j = 0 ; j < rightResult.size(); ++j) {
                        if (input[index] == '+') {
                            result.push_back(leftResult[i] + rightResult[j]);
                        }
                        else if (input[index] == '-') {
                            result.push_back(leftResult[i] - rightResult[j]);
                        }
                        else if (input[index] == '*') {
                            result.push_back(leftResult[i] * rightResult[j]);
                        }
                    }
                }
            }
        }
        cache[input] = result;
        return result;
    }
public:
    std::vector<int> diffWaysToCompute(std::string input) {
        std::unordered_map<std::string, std::vector<int>> cache;
        return diffWaysToCompute(input, cache);
    }
};

