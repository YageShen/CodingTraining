#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool is_ip(const string &ip)
{
    string seg;
    istringstream iss(ip);
    int j = 0;
    while(getline(iss, seg, '.'))
    {
        if(++j > 4 || seg.empty() || stoi(seg) > 255 || stoi(seg) < 0)
            return false;
    }    
    return j == 4;
}

int main()
{
    string ip;
    while(cin >> ip)
    {
        if(is_ip(ip))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
