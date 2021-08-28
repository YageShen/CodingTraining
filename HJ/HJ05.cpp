#include <iostream>
#include <string>
#include <set>
#include "math.h"

using namespace std;

int main()
{
  string str;
  while(cin >> str) 
  {
    int len = str.size();
    int sum = 0;
    for (int i = len - 1, j = 0; i > 1; --i, ++j)
    {
      int bit_num = 0;
      if(str[i] >= '0' && str[i] <= '9') {
        bit_num = str[i] - '0';
      }
      else if(str[i] >= 'A' && str[i] <= 'F') {
        bit_num = 10 + (str[i] - 'A');
      }
      else{
        printf("error input\n");
        continue;
      }
      sum += bit_num * pow(16, j);
    }
    cout << sum << endl;
  }
  return 0;
}