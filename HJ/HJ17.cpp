#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct position
{
  int x = 0;
  int y = 0;
};

void moveOneStep(string str, position &pos)
{
  int len = str.size();
  int dist;
  bool flag = false;
  if(len == 2)
  {
    if(str[1] >= '0' && str[1] <= '9')
      flag = true;
  }
  if(len == 3)
  {
    if(str[1] >= '0' && str[1] <= '9' && str[2] >= '0' && str[2] <= '9')
      flag = true;
  }
  if(flag)
  {
    dist = stoi(str.substr(1));
    switch (str[0])
    {
    case 'A':
      pos.x -= dist;
      break;
    case 'D':
      pos.x += dist;
      break;
    case 'W':
      pos.y += dist;
      break;
    case 'S':
      pos.y -= dist;
      break;
    default:
      break;
    }
  } 
}

int main()
{
    string input;
    position pos;
    cin >> input;
    while(input.size() > 0)
    {
      int index = input.find(';');
      string substr = input.substr(0, index);
      moveOneStep(substr, pos);
      input = input.substr(index+1);
    }
    cout << pos.x << ',' << pos.y << endl;
    return 0;
}
