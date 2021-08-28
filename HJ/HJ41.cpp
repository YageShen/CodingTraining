#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int kind;
    vector<int> list;
    set<int> res = {0};
    while(cin >> kind)
    {
        res.insert(0);
        for(int i(0); i < kind; ++i)
        {
            int weight;
            cin >> weight;
            list.push_back(weight);
        }
        for(int i(0); i < kind; ++i)
        {
            int num;
            cin >> num;
            list.push_back(num);
        }
    
        for(int i(0); i < kind; ++i)
        {
            int weight = list[i];
            int num = list[kind + i];
            for(int j(0); j < num; ++j)
            {
                set<int> tempRes = res;
                for(set<int>::iterator iter = tempRes.begin(); iter != tempRes.end(); ++iter)
                {
                    res.insert(*iter + weight);
                }
            }   
        }
        cout << res.size() << endl;
        res.clear();
        list.clear();
    }

    
    return 0;
}