#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int stu_num, op_num;
    vector<int> stu_list;
    while(cin >> stu_num >> op_num)
    {
      for(int i(0); i < stu_num; ++i)
      {
        int score;
        cin >> score;
        stu_list.push_back(score);
      }

      for(int j(0); j < op_num; ++j)
      {
        char op;
        cin >> op;
        if(op == 'U') // modify score
        {
          int stu_id, new_score;
          cin >> stu_id >> new_score;
          stu_list[stu_id - 1] = new_score;
        }

        if(op == 'Q') // query score
        {
          int id_begin, id_end;
          cin >> id_begin >> id_end;
          if(id_begin > id_end) {
            int temp = id_end;
            id_end = id_begin;
            id_begin = temp;
          }
          int max_score = 0;
          for(int z(id_begin); z <= id_end; ++z)
          {
            if(stu_list[z - 1] > max_score)
              max_score = stu_list[z - 1];
          }
          cout << max_score << endl;
        }
      }

      stu_list.clear();      
    }

    return 0;
}