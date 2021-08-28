#include <iostream>
#include <vector>

using namespace std;

int a[10][10];
int rows, cols;
vector<int> res;

bool dfs(int r, int c)
{
    if(r == (rows - 1) && c == (cols - 1) && a[r][c] == 0)
    {
        res.push_back(r); res.push_back(c);
        return true;
    }
    else if(r == rows || c == cols || r < 0 || c < 0)
        return false;
    else if(a[r][c] == 0)
    {
        a[r][c] = 1;
        res.push_back(r); res.push_back(c);
        if(dfs(r+1, c)  || dfs(r, c+1) || dfs(r-1, c)|| dfs(r, c-1))
            return true;
        else
        {
            a[r][c] = 0;
            res.pop_back(); res.pop_back();
            return false;
        }
    }
    return false;
}

int main()
{
    while(cin >> rows >> cols)
    {
        for(int r(0); r < rows; ++r)
            for(int c(0); c < cols; ++c)
            {
                int temp;
                cin >> temp;
                a[r][c] = temp;
            }
        dfs(0, 0);
        for(int i(0); i < res.size(); i += 2)
        {
            cout << '(' << res[i] << ',' << res[i+1] << ')' << endl;
        }
        res.clear();
    }
    
    return 0;
}