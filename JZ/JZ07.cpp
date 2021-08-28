class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 1)
            return n;
        else
        {
            int last = 1, llast = 0, cur;
            for(int i(2); i <= n; ++i)
            {
                cur = last + llast;
                llast = last;
                last = cur;
            }
            return cur;
        }
    }
};