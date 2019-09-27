class Solution {
private:
    double myPowInternal(double x, long n) {
        if (n == 0) {
            return 1;
        }
        double value = myPowInternal(x, n / 2);
        return n % 2 == 0 ? value * value : value * value * x;
    }
public:
    double myPow(double x, long n) {
       if (n < 0) {
           n = -n;
           x = 1 / x;
       }
       return myPowInternal(x, n);
    }
};