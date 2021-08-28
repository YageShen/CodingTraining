#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        string code = str;
        for(int i(0); i < str.size(); ++i)
        {
            if(str[i] >= 'A' && str[i] <= 'Y')
            {
               code[i] = (char)(str[i] - 'A' + 'a' + 1);
            }
            else if(str[i] == 'Z')
                code[i] = 'a';
            else if(str[i] >= 'a' && str[i] <= 'z')
            {
                int n = str[i] - 'a';
                if(n < 15)
                    code[i] = (char)(n / 3 + '2');
                else if(n < 19)
                    code[i] = '7';
                else if(n < 22)
                    code[i] = '8';
                else
                     code[i] = '9';
            }
        }
        cout << code << endl;
    }
    return 0;
}