#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x, y, z;
    // x + y + z = 100
    // 5x + 3y + z / 3 = 100
    // => 14x + 8y = 200
    for(int i(0); i < 200 / 14; ++i)
    {
        int a = 200 - 14 * i;
        if(a % 8 == 0)
        {
            cout << i << ' ' << a / 8 << ' ' << 100 - i - a / 8  << endl; 
        }
    }
    return 0;
}