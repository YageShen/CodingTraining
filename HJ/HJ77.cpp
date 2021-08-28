#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<int> train;
int num;
stack<int> out;
set<vector<int>> res;

void dfs(int idx, vector<int> out, vector<int> in)
{
    if(out.size() == train.size())
    {
        res.insert(out);
        return;
    }
    if(!in.empty())
    {
        out.push_back(*(in.end()-1));
        in.pop_back();
        dfs(idx, out, in);
        in.push_back(*(out.end()-1));
        out.pop_back();
    }
    if(idx != train.size())
    {
        in.push_back(train[idx]);
        idx ++;
        dfs(idx, out, in);
        in.pop_back();
    }
}

int main()
{
    while(cin >> num)
    {
        for(int i(0); i < num; ++i)
        {
            int temp;
            cin >> temp;
            train.push_back(temp);
        }
        vector<int> out;
        vector<int> in;
        dfs(0, out, in);
        for(auto iter = res.begin(); iter != res.end(); ++iter)
        {
            for(int i(0); i < num; ++i)
            {
                cout << (*iter)[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}