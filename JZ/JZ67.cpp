class Solution {
public:
    int cutRope(int number) {
        int ret = 1;
        while(number > 4) {
            ret *= 3;
            number -= 3;
        }
        return ret * number;
    }
};