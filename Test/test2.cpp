#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ErrorLog
{
  string name;
  int line;
  int count = 1;
};

void getFilename(string &filename)
{
  reverse(filename.begin(), filename.end());
  int pos = filename.find('\\');
  if(pos > 16)
    pos = 16; 
  filename = filename.substr(0, pos);
  reverse(filename.begin(), filename.end());
}

void recordErrorLog(const ErrorLog &err, vector<ErrorLog> &res)
{
  bool repeat = false;
  for(int i(0); i < res.size(); ++i)
  {
    if (err.name == res[i].name && err.line == res[i].line)
    {
      res[i].count += 1;
      repeat = true;
      break;
    }
  }
  if(!repeat)
  {
    res.push_back(err);
  }
}

static bool Compare(ErrorLog &a, ErrorLog &b)
{
  return a.count > b.count;
}

int main()
{
    string file_name;
    int line;
    vector<ErrorLog> errVec;
    ErrorLog err;
    int error_num = 0;
    while(cin >> file_name >> line)
    {
      // if(file_name == "z")
      //   break;      
      getFilename(file_name);
      err.name = file_name; err.line = line;
      recordErrorLog(err, errVec);
    }
    sort(errVec.begin(), errVec.end(), Compare);
    for(int i(0); i < 8; ++i)
    {
      if(i >= errVec.size())
        break;
      cout << errVec[i].name << ' ' << errVec[i].line << ' ' << errVec[i].count << endl;
    }

    return 0;
}