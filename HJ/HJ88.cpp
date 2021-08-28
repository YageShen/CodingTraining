#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, int> rule = {{"2", 1}, {"3", 2}, {"4", 3}, {"5", 4}, {"6", 5}, {"7", 6}, {"8", 7}, {"9", 8}, 
                                  {"10", 9}, {"J", 10}, {"Q", 11}, {"K", 12}, {"A", 13}, {"jorker", 14}, {"JORKER", 15}};

int compare(string s1, string s2)
{
    int len1, len2;
    char c1, c2;
    if((len1 = s1.size()) && (len2 = s2.size()))
    {
        c1 = s1[0]; c2 = s2[0];
    } else
        return 0;
    int seg_num1 = 1, seg_num2 = 1;
    while(s1.find(' ') != -1)
    {
        seg_num1 ++;
        s1 = s1.substr(s1.find(' ')+1);
    }
    while(s2.find(' ') != -1)
    {
        seg_num2 ++;
        s2 = s2.substr(s2.find(' ')+1);
    }
    
    if(seg_num1 == seg_num2)
      return (rule.find(s1)->second < rule.find(s2)->second); 
    else if(seg_num1 == 2 && len1 == 11)
      return 0;
    else if(seg_num2 == 2 && len2 == 11)
      return 1;
    else if(seg_num1 == 4)
      return 0;
    else if(seg_num2 == 4)
      return 1;
    else
      return -1;
}

int main()
{
    
    string input1, input2, str;
    getline(cin, str);
    int idx = str.find('-');
    input1 = str.substr(0, idx);
    input2 = str.substr(idx+1);
    int res = compare(input1, input2);
    if(res == 0)
      cout << input1 << endl;
    else if(res == 1)
      cout << input2 << endl;
    else
      cout << "ERROR" << endl;
}