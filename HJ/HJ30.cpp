#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char reverseChar(const int &ch)
{
    int re_ch = 0;
    char temp;
    for(int i(0); i < 4; ++i)
    {
        re_ch += ((ch >> i )& 0x01) << (3 - i);
    }
    if(re_ch < 10)
        temp = '0' + re_ch;
    else if(re_ch < 16)
        temp = re_ch - 10 + 'A';
    return temp;
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        vector<char> vec1, vec2; // vec1:偶数下标, vec2:奇数下标
        string mergeStr = str1 + str2;
        for(int i(0); i < mergeStr.size(); ++i)
        {
            if(i % 2 == 0)
                vec1.push_back(mergeStr[i]);
            else
                vec2.push_back(mergeStr[i]);
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        
        string reverseStr;
        for(int i(0); i < vec1.size() + vec2.size(); ++i)
        {
            char temp = (i % 2 == 0 ? vec1[i/2] : vec2[i / 2]);
            if(isdigit(temp))
                temp = reverseChar(temp - '0');
            else if(temp >= 'a' && temp <= 'f')
                temp = reverseChar(temp - 'a' + 10);
            else if(temp >= 'A' && temp <= 'F')
                temp = reverseChar(temp - 'A' + 10);
            reverseStr += temp;
        }
        
        cout << reverseStr << endl;
    }
    return 0;
}