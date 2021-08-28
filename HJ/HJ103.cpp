#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int num;
//     memset(dp, char(1), sizeof(dp));
    while(cin >> num)
    {
        vector<int> vec;
        for(int i(0); i < num; ++i)
        {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        vector<int> dp(num, 1);
        int res = 1;
        for(int i(1); i < num; ++i)
        {
            for(int j(0); j < i; ++j)
            {
                dp[i] = vec[i] > vec[j] ? max(dp[i], dp[j] + 1) : dp[i];
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}