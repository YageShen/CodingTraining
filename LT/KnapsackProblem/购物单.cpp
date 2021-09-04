#include <iostream>
#include <vector>

using namespace std;

int main() {
    int money, num;
    cin >> money >> num;
    money /= 10;
    vector<vector<int>> dp(num+1, vector<int>(money+1, 0));
    vector<vector<int>> price(num, vector<int>(3, 0));
    vector<vector<int>> priceMultiPriority(num, vector<int>(3, 0));
    for(int i = 0;i < num; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a /= 10;
        if(c == 0) {
            price[i][0] = a;
            priceMultiPriority[i][0] = a * b;
        }
        else {
            if (price[c-1][1] == 0) {
                price[c-1][1] = a;
                priceMultiPriority[c-1][1] = a * b;
            }
            else if(price[c-1][2] == 0) {
                price[c-1][2] = a;
                priceMultiPriority[c-1][2] = a * b;
            }
        }
    }
    
    for(int i = 1; i <= num; ++i) {
        for(int j = 1; j <= money; ++j) {
            int a = price[i-1][0], a_multi = priceMultiPriority[i-1][0];
            int b = price[i-1][1], b_multi = priceMultiPriority[i-1][1];
            int c = price[i-1][2], c_multi = priceMultiPriority[i-1][2];
            
            dp[i][j] = j >= a ? max(dp[i-1][j-a] + a_multi, dp[i-1][j]) : dp[i-1][j];
            dp[i][j] = j >= a + b ? max(dp[i-1][j-a-b] + a_multi + b_multi, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= a + c ? max(dp[i-1][j-a-c] + a_multi + c_multi, dp[i][j]) : dp[i][j];
            dp[i][j] = j >= a + b + c ? max(dp[i-1][j-a-b-c] + a_multi + b_multi + c_multi, dp[i][j]) : dp[i][j];
        }
    }
    cout << dp[num][money] * 10 << endl;
    return 0;
}