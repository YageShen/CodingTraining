#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        bool right = true;
        int len = str.size();
        if(len <= 8)
        {
            cout << "NG" <<endl;
            right = false;
            continue;
        }
        
        int flag[4] = {0};
        for(int i(0); i < len; ++i)
        {
             if(str[i] >= '0' && str[i] <= '9')
                 flag[0] = 1;
            else if(str[i] >= 'a' && str[i] <= 'z')
                flag[1] = 1;
            else if(str[i] >= 'A' && str[i] <= 'Z')
                flag[2] = 1;
            else
                flag[3] = 1;
        }
        if(flag[0]+flag[1]+flag[2]+flag[3] < 3)
        {
            cout << "NG" << endl;         
            right = false;
            continue;
        }

        // string substr, delStr;
        for(int i(0); i <= len - 3; ++i)
        {
            string substr = str.substr(i, 3);
            string delStr = str.substr(0, i) + ' ' + str.substr(i+3);
            if(delStr.find(substr) != -1)
            {
                cout << "NG" << endl;
                right = false;
                break;
            }
        }
        
        if(right)
        {
            cout << "OK" << endl;
        }
    }
    return 0;
}