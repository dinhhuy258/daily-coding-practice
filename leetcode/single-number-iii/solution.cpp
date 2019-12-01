class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int setBits = 0;
        for (auto& num: nums) {
            setBits ^= num;
        }
        
        // Calculate the right most set bit
        // number: A10..0
        // number - 1 =  A01..1
        // ~(number - 1) = ~A10..0
        // number & (number - 1) = A10..0 & ~A10..0 = 0..010..0
        int num1SetBit = setBits & ~(setBits - 1);
         
        int num1 = 0, num2 = 0;
        for (auto& num: nums) {
            if (num1SetBit & num) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};