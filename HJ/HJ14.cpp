#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// int main()
// {
//     int n;
//     multiset<string> ss;
//     string str;
//     cin >> n;
//     for(int i = 0; i < n; ++i)
//     {
//         cin >> str;
//         ss.insert(str);
//     }
//     for(set<string>::iterator it = ss.begin(); it != ss.end(); ++it)
//     {
//         cout << *it << endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    vector<string> vec;
    string str;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> str;
        vec.push_back(str);
    }
    sort(vec.begin(),  vec.end());
    for(auto s : vec)
    {
        cout << s << endl;
    }
    return 0;
}