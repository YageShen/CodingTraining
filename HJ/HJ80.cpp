#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int len1, len2;
    while(cin >> len1)
    {
        set<int> ss;
        int temp;
        for(int i(0); i < len1; ++i)
        {
            cin >> temp;
            ss.insert(temp);
        }
        cin >> len2;
        for(int i(0); i < len2; ++i)
        {
            cin >> temp;
            ss.insert(temp);
        }
//         sort(ss.begin(), ss.end());
        for(auto iter : ss)
            cout << iter;
        cout << endl;
    }
    return 0;
}