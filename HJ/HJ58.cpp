#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, k;
    multiset<int> s;
    int temp;
    while(cin >> n >> k)
    {
        for(int i(0); i < n; ++i)
        {
            cin >> temp;
            s.insert(temp);            
        }
        set<int>::iterator it = s.begin();
        for(int i(0); i < k; ++i)
        {
            cout << *it << ' ';
            ++it;
        }
        cout << endl;
        s.clear();
    }
    return 0;
}