#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    int pickNum = 0;
};

int findIdx(const vector<Student> &s, const string &name)
{
    for(int i(0); i < s.size(); ++i)
    {
        if(s[i].name == name)
            return i;
    }
    return -1;
}

int main()
{
    int n1;
    while(cin >> n1)
    {
        vector<Student> studentList;
        for(int i(0); i < n1; ++i)
        {
            Student temp;
            cin >> temp.name;
            studentList.push_back(temp);
        }
        int n2;
        int invalidNum = 0;
        cin >> n2;
        for(int i(0); i < n2; ++i)
        {
            string temp;
            cin >> temp;
            int idx = findIdx(studentList, temp);
            if(idx == -1)
                invalidNum ++;
            else
                studentList[idx].pickNum ++;
        }
        
        for(int i(0); i < studentList.size(); ++i)
        {
            cout << studentList[i].name << " : " << studentList[i].pickNum << endl;
        }
        cout << "Invalid : " << invalidNum << endl;
    }
    return 0;
}