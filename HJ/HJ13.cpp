#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
  string str;
  stack<string> s;
  getline(cin, str);
  while(str.size() > 0)
  {
    int pos = str.find(' ');
    if(pos != string::npos)
    {
      string substr = str.substr(0, pos);
      s.push(substr);
      str = str.substr(pos+1); 
    }
    else
    {
      s.push(str);
      break;      
    }
  }
  while(!s.empty())
  {
    cout << s.top() << ' ';
    s.pop();
  }
  cout << endl;
  return 0;
}