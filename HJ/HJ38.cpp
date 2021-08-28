#include <iostream>

using namespace std;

int main()
{
    float height;
    cin >> height;
    float dist = height;
    for(int i(0); i < 4; ++i)
    {
        dist += height;
        height /= 2;
    }
    cout << dist << endl;
    cout << height / 2 << endl;
    return 0;
}