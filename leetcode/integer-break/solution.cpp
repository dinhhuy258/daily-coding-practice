class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            // 2 -> 1 * 1 = 1, 3 -> 2 * 1 = 2
            return n - 1;
        }
        else if (n % 3 == 0) {
            return std::pow(3, n / 3);
        }
        else if (n % 3 == 1) {
            return std::pow(3, n / 3 - 1) * 4;
        }
        // n % 3 == 2
        return std::pow(3, n / 3) * 2; 
    }
};

