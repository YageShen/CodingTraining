#include <iostream>
#include <string>
#include <set>
#include "math.h"

using namespace std;

int main()
{
  double d;
  cin >> d;
  cout << ((((int)(d * 10) % 10) >= 5) ? (int)d + 1 : (int)d) << endl;
  return 0;
}