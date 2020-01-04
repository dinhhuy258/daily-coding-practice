class Solution { 
private:
    int sumSquaresOfDigits(int n) {
        int result = 0;
        while (n != 0) {
            result += std::pow(n % 10, 2);
            n /= 10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> visited;
        while(n != 1) {
            if (visited.find(n) != visited.end()) {
                return false;
            }
            visited.insert(n);
            n = sumSquaresOfDigits(n);
        }
        return true;
    }
};
