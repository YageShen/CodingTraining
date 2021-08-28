#include<iostream>
#include<set>
using namespace std;

int main()
{
  int N;
  int n;
  set<int> ss;
  while(cin >> N) {
    ss.clear();
    while(N--) {
      cin >> n;
      ss.insert(n);
    }
    for(set<int>::iterator it = ss.begin(); it != ss.end(); ++it) {
      cout << *it << endl;
    }
  }
  return 0;
}