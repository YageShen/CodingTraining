#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    while(cin >> input)
    {
        int len = input.size();
        string output;
        int count[26] = {0};
        int min = 20;
        for(int i(0); i < len; ++i)
        {
            count[input[i] - 'a'] ++;
        }
        for(int i(0); i < 26; ++i)
        {
            if((count[i] < min) && (count[i] != 0))
            {
                min = count[i];
            }
        }
        for(int i(0); i < len; ++i)
        {
            if(count[input[i] - 'a'] > min )
            {
                output += input[i];
            }
        }
        
        cout << output << endl;
    }
    return 0;
}