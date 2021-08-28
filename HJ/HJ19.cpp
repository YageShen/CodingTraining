#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct ErrorMsg
{
  string name;
  int line;
  int count = 1;
};

void getFileName(string &filename)
{
  reverse(filename.begin(), filename.end());
  filename = filename.substr(0, filename.find('\\'));
  if(filename.size() > 16)
    filename = filename.substr(0, 16);
  reverse(filename.begin(), filename.end());
}

void recordError(const ErrorMsg &msg, vector<ErrorMsg> &res)
{
  bool repeat = false;
  for(int i(0); i < res.size(); ++i)
  {
    if(res[i].name == msg.name && res[i].line == msg.line)
    {
      res[i].count ++;
      repeat = true;
      break;
    }
  }
  if(!repeat)
    res.push_back(msg);
}

int main()
{
  string file_name;
  int line;
  ErrorMsg msg;
  vector<ErrorMsg> res;
  while(cin >> file_name >> line)
  {
    getFileName(file_name);
    msg.name = file_name; 
    msg.line = line;
    recordError(msg, res);
  }

  int min_idx = res.size() > 8 ? res.size() - 8 : 0;
  for(int i(min_idx); i < res.size(); ++i)
  {
    cout << res[i].name << ' ' << res[i].line << ' ' << res[i].count << endl;
  }
  return 0;
}
