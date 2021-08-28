#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0;
        for(int i(1); i <= n; ++i) sum += i;
        int row = 0, col = 0, next_row = 0;
        for(int i(1); i <= sum; ++i) // 第i行
        {
            a[row][col] = i;
            if(row == 0)
            {
                next_row ++;
                row = next_row; col = 0;
            }
            else
            {
                row -= 1; col += 1;
            }
        }
        
        for(int i(0); i < n; ++i)
        {
            for(int j(0); j < n - i; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}