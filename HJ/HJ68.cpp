#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int score;
};

static bool compareDown(const Student &s1, const Student &s2)
{
    return s1.score > s2.score;
}

static bool compareUp(const Student &s1, const Student &s2)
{
    return s1.score < s2.score;
}

int main()
{
    int num, order;
   vector<Student> studentList;
    while(cin >> num >> order)
    {
        Student temp;
        for(int i(0); i < num; ++i)
        {
        cin >> temp.name >> temp.score;
        studentList.push_back(temp);            
        }
        if(order == 0)
            stable_sort(studentList.begin(),  studentList.end(), compareDown);
        else
            stable_sort(studentList.begin(),  studentList.end(), compareUp);
        
        for(vector<Student>::iterator iter = studentList.begin(); iter != studentList.end(); ++iter)
        {
            cout << iter->name << ' ' << iter->score << endl;
        }
        studentList.clear();
    }
    return 0;
}