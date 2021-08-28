#include <iostream>
#include <string>
#include <set>
#include "math.h"

using namespace std;

int main()
{
  long n;
  cin >> n;
  while(n != 1)
  {
    bool flag = false;
    for(int i = 2; i <= n / 2; ++i)
    {
      if(n % i == 0)
      {
        n /= i;
        printf("%d ", i);
        flag = true;
        break;
      }
    }
    if(!flag) {
      printf("%ld ", n);
      break;     
    }
  }
  return 0;
}