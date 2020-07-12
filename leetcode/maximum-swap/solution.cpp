class Solution {
public:
    int maximumSwap(int num) {
        auto numStr = std::to_string(num);
        auto numLength = numStr.size();
        char maxIndex = -1;
        char swapIndex1 = -1;
        char swapIndex2 = -1;

        for (int i = numLength - 1; i >= 0; --i) {
            if (maxIndex == -1 || numStr[i] > numStr[maxIndex]) {
                maxIndex = i;
            }
            else if (numStr[i] < numStr[maxIndex]) {
                swapIndex1 = i;
                swapIndex2 = maxIndex;
            }
        }

        if (swapIndex1 != -1 && swapIndex2 != -1) {
            std::swap(numStr[swapIndex1], numStr[swapIndex2]);
        }
        return std::stoi(numStr);
    }
};

