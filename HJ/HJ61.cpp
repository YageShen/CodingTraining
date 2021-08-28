#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    vector<vector<int>> dp(11, vector<int>(11, 1));
    while(cin >> m >>n)
    {
        if(dp[m][n] == 1)
            for(int i(2); i <= m; ++i)
            {
                for(int j(2); j <= n; ++j)
                {
                    dp[i][j] = dp[i][j-1];
                    if(i >= j)
                        dp[i][j]+= dp[i-j][j];               
                }
            }
        
        cout << dp[m][n] << endl;
    }
    return 0;
}