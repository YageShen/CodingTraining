class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        int dp[index];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i(1); i < index; ++i) {
            int num2 = 2 * dp[p2], num3 = 3 * dp[p3], num5 = 5 * dp[p5];
            dp[i] = min(min(num2, num3), num5);
            if(dp[i] == num2)
                ++p2;
            if(dp[i] == num3)
                ++p3;
            if(dp[i] == num5)
                ++p5;
        }
        return dp[index-1];
    }
};