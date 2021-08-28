#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str;
    set<char> ss;
    int n = 0;
    cin >> str;
    for(auto c : str)
    {
        if(ss.count(c) == 0)
        {
            n++;
            ss.insert(c);
        }
    }
    cout << n << endl;
    return 0;
}