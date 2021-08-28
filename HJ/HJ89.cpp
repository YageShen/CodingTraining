#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

map<string, int> rule = {{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, 
                                  {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"joker", 14}, {"JOKER", 15}};

int num[4];
bool vis[4] = {false};
vector<string> res;

bool dfs(int sum)
{
    if(sum == 24 && vis[0] && vis[1] && vis[2] && vis[3])
        return true;
    else
    {
        for(int i(0); i < 4; ++i)
        {
            if(!vis[i])
            {
                vis[i] = true;
                res.push_back("+"); res.push_back(to_string(num[i]));
                if(dfs(sum + num[i]))
                {
                    return true;
                }
                res.pop_back(); res.pop_back();                    

                res.push_back("-"); res.push_back(to_string(num[i]));
                if(dfs(sum - num[i]))
                    return true;
                res.pop_back(); res.pop_back();
                if(sum != 0)
                {
                    res.push_back("*"); res.push_back(to_string(num[i]));
                    if(dfs(sum * num[i]))
                        return true;
                    res.pop_back(); res.pop_back();
                    res.push_back("/"); res.push_back(to_string(num[i]));
                    if(dfs(sum / num[i]))
                        return true;
                    res.pop_back(); res.pop_back();                          
                }

              
                vis[i] = false;
            }
        }
    }
    return false;
}

int main()
{
    string input[4];
    
    while(cin >> input[0] >> input[1] >> input[2] >> input[3])
    {
        for(int i(0); i < 4; ++i)
            num[i] = rule.find(input[i])->second;
        if(num[0] > 13 || num[1] > 13 || num[2] > 13 || num[3] > 13)
        {
            cout << "ERROR" << endl;
            break;
        }    
        else if(dfs(0))
        {
          cout << "TRUE" << endl;
        }
        else
        {
            cout << "NONE" << endl;
        }
        
        
    }
    
    int i = 0;

    
    return 0;
}