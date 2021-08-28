#include <iostream>
#include <set>

using namespace std;
int main()
{
    int n;
    set<int> ss;
    cin >> n;
    while(n > 0)
    {
        int bit = n % 10;
        if(ss.count(bit) == 0)
        {
            ss.insert(bit);
            cout << bit;
        }
        n /= 10;
    }
    cout << endl;
    return 0;
}