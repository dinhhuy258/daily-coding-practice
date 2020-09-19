class Solution {
private:
    void sequentialDigits(int low, int high, int startNumber, std::vector<int>& result) {
        int number = 0;
        for (int i = startNumber; i <= 9; ++i) {
            number = number * 10 + i;
            if (number > high) {
                break;
            }
            else if (number >= low) {
                result.push_back(number);
            }
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            sequentialDigits(low, high, i, result);
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};

