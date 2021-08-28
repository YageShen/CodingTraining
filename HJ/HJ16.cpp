#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int money, num;
    vector<vector<int>> prices(61, vector<int>(3, 0));
    vector<vector<int>> pricesMultiPriority(61, vector<int>(3, 0));
    cin >> money >> num;
    money /= 10;
    for(int i(0); i < num; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a /= 10;
        if(c == 0) // 主件
        {
            prices[i][0] = a;
            pricesMultiPriority[i][0] = a * b;
        }
        else // 附件
        {
            if(prices[c-1][1] == 0) // 第一个附件
            {
                prices[c-1][1] = a;
                pricesMultiPriority[c-1][1] = a * b;
            }
            else // 第二个附件
            {
                prices[c-1][2] = a;
                pricesMultiPriority[c-1][2] = a * b;
            }
        }
    }
    
    vector<vector<int>> dp(num+1, vector<int>(money+1, 0));
    for(int i(1); i <= num; ++i)
    {
        for(int j(1); j <= money; ++j)
        {
            int a = prices[i-1][0], a_multi = pricesMultiPriority[i-1][0];
            int b = prices[i-1][1], b_multi = pricesMultiPriority[i-1][1];
            int c = prices[i-1][2], c_multi = pricesMultiPriority[i-1][2];
            dp[i][j] = j >= a ? max(dp[i-1][j], dp[i-1][j-a] + a_multi) : dp[i-1][j];
            dp[i][j] = j >= (a + b) ? max(dp[i][j], dp[i-1][j-a-b] + a_multi + b_multi) : dp[i][j];
            dp[i][j] = j >= (a + c) ? max(dp[i][j], dp[i-1][j-a-c] + a_multi + c_multi) : dp[i][j];
            dp[i][j] = j >= (a +b + c) ? max(dp[i][j], dp[i-1][j-a-b-c] + a_multi + b_multi + c_multi) : dp[i][j];
        }
    }
    cout << dp[num][money] * 10 << endl;
    
    return 0;
}