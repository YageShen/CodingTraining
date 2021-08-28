class Solution {
public:
    int rectCover(int number) {
        if(number <= 3)
            return number;
        else
        {
            int llast = 2, last = 3, cur;
            for(int i = 4; i <= number; ++i) {
                cur = last + llast;
                llast = last;
                last = cur;
            }
            return cur;
        }
    }
};