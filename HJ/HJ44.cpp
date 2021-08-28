#include <iostream>

using namespace std;

int a[9][9] = {0};
bool signal = false;

bool check(int row, int col, int val)
{
    for(int i(0); i < 9; ++i)
    {
        if(a[row][i] == val || a[i][col] == val)
            return false;
    }
    int idx_row = row / 3 * 3;
    int idx_col = col / 3 * 3;
    for(int i(idx_row); i < idx_row + 3; ++i)
    {
        for(int j(idx_col); j < idx_col + 3; ++j)
        {
            if(a[i][j] == val)
                return false;
        }
    }
    return true;
}

void dfs(int row, int col)
{
    if(row == 9)
    {
        signal = true;
    }
    if(a[row][col] == 0)
    {
        for (int i(1); i <= 9; ++i)
        {
            if(check(row, col, i))
            {
                a[row][col] = i;
                if(col == 8)
                    dfs(row+1, 0);
                else
                    dfs(row, col+1);
                
                if(!signal)
                    a[row][col] = 0;
            }
        } 
    }
    else
    {
        if(col == 8)
            dfs(row+1, 0);
        else
            dfs(row, col+1);
    }
}
    
int main()
{
    for(int i(0); i < 9; ++i)
    {
        for(int j(0); j < 9; ++j)
        {
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
    for(int i(0); i < 9; ++i)
    {
        for(int j(0); j < 9; ++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}