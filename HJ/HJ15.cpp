#include <iostream>

using namespace std;

int main()
{
    int n;
    int num = 0;
    cin >> n;
    while(n > 0)
    {
        num += n & 0x1;
        n = n >> 1;
    }
    cout << num << endl;
    return 0;
}