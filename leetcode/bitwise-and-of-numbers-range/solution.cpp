class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        unsigned int i = (1 << 31);
        while(i != 0) {
            if ((n & i) != (m & i)) {
                break;
            }
            result =  ((n & i) != 0) ? result | i : result;
            i >>= 1;
        }
        
        return result;
    }
};
