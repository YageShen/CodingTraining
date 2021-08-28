#include <iostream>
#include <string>
#include <set>
#include <map>   
#include "math.h"

using namespace std;

int main()
{
  map<int, int> m;
  int n;
  int key, value;
  cin >> n;
  for(int i(0); i < n; ++i){
    cin >> key >> value;
    if(m.count(key) >= 0)
      m[key] += value;
    else
      m.insert(pair<int, int>(key, value));
  }
  for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
    cout << iter->first << ' ' << iter->second << endl;
  }
  
  return 0;
}