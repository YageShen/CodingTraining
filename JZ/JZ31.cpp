class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int num = 0;
        for(int i(1); i <= n; ++i) {
            int temp = i;
            while(temp) {
                if(temp % 10 == 1)
                    ++num;
                temp /= 10;
            }
        }
        return num;
    }
};