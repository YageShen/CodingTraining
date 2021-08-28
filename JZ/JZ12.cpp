class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }
        double res = 1.0;
        double x = base;
        while(exponent > 0) {
            if(exponent & 0x01) {
                res *= x;
            }
            x *= x;
            exponent >>= 1;
        }
        return res;
    }
};