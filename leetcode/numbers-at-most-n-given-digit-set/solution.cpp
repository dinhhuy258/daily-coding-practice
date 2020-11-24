class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        std::string number = std::to_string(n);
        int numberLength = number.size();
        int digitsLength = digits.size();
        int ans = 0;
        for (int i = 1; i < numberLength; ++i) {
            ans += std::pow(digitsLength, i);
        }
        std::vector<int> dp = std::vector(numberLength + 1, 0);
        dp[numberLength] = 1;
        for (int i = numberLength - 1 ; i >= 0; --i) {
            for (auto digit: digits) {
                if (digit < std::string(1, number[i])) {
                    dp[i] += std::pow(digitsLength, numberLength - i - 1);
                }
                else if (digit == std::string(1, number[i])) {
                    dp[i] += dp[i + 1];
                }
            }
        }

        return ans + dp[0];
    }
};

