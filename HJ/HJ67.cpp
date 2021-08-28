#include <iostream>
#include <cstring>

using namespace std;

double num[4] = {0};
bool vis[4] = {false};

bool dfs(double sum)
{
    if(sum < 24 + 0.00001 && sum > 24 - 0.00001)
        return true;
    else
    {
        for(int i(0); i < 4; ++i)
        {
            if(!vis[i])
            {
                vis[i] = true;
                if(dfs(sum + num[i]) || dfs(sum - num[i]) || dfs(sum * num[i]) || dfs(sum / num[i]))
                    return true;
                vis[i] = false;
            }
        }
    }
    return false;
}

int main()
{
    while(cin >> num[0] >> num[1] >> num[2] >> num[3])
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(0))
            cout << "true" << endl;
        else
            cout << "false" << endl;        
    }

    return 0;
}