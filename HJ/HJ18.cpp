#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_ip(string ip)
{
  int j = 0;
  string seg;
  istringstream iss(ip);
  while(getline(iss, seg, '.'))
  {
    if(++j > 4 || seg.empty() || stoi(seg) > 255)
      return false;
  }
  return j == 4;
}

string toBinary(int num)
{
  string binaryStr;
  while(num > 0)
  {
    binaryStr = ((num & 0x1) ? '1' : '0') + binaryStr;
    num = num >> 1;
  }
  while(binaryStr.size() < 8)
  {
    binaryStr = '0' + binaryStr;
  }
  return binaryStr;
}

bool is_mask(string mask)
{
  if(is_ip(mask))
  {
    string bMask;
    string seg;
    istringstream iss(mask);
    while(getline(iss, seg, '.'))
    {
      bMask += toBinary(stoi(seg));
    }
    int idx = bMask.find('0');
    if(idx <= 0)
      return false;
    else
    {
      string sub_zero;
      // sub1 = bMask.substr(0,idx);
      sub_zero = bMask.substr(idx);
      if(sub_zero.find('1') != -1)
        return false;
      else
        return true;
    }
  }
  return false;
}

bool is_private(int first_seg, int second_seg)
{
  // int idx = ip.find('.');
  // int first_seg = stoi(ip.substr(0, idx));
  // ip = ip.substr(idx + 1);
  // int second_seg = stoi(ip.substr(0, ip.find('.')));
  if(first_seg == 10)
    return true;
  else if(first_seg == 172 && second_seg >= 16 && second_seg <= 31)
    return true;
  else if(first_seg == 192 && second_seg == 168)
    return true;

  return false;
}

int main()
{
    int res[7] = {0};
    string ip, mask, str;
    // getline(cin, str);
    while(cin >> str)
    {
      int idx = str.find('~');
      if(idx != -1)
      {
        ip = str.substr(0, idx);   
        mask = str.substr(idx + 1); 
        if(!is_mask(mask))
        {
          res[5]++;
        }
        else if(!is_ip(ip))
        {
          res[5]++;
        }
        else
        {
          idx = ip.find('.');
          int first_seg = stoi(ip.substr(0, idx));
          ip = ip.substr(idx + 1);
          int second_seg = stoi(ip.substr(0, ip.find('.')));
          if(is_private(first_seg, second_seg))
            res[6]++;
          if(first_seg >= 1 && first_seg <= 126)
            res[0]++;
          else if(first_seg >= 128 && first_seg <= 191)
            res[1]++;
          else if(first_seg >= 192 && first_seg <= 223)
            res[2]++;
          else if(first_seg >= 224 && first_seg <= 239)
            res[3]++;
          else if(first_seg >= 240)
            res[4]++;
        }  
      }      
    }
    for(int i(0); i < 7; ++i)
    {
      printf("%d ", res[i]);
    }
    printf("\n");
    // cout << is_ip(ip) << endl << is_ip(mask) << endl;
    return 0;
}
