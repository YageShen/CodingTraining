#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int normalScore = 0;
    int finalScore = 0;
};

static bool compareDown(const Student &s1, const Student &s2)
{
    return s1.finalScore > s2.finalScore;
}

int main() {
    int nums;
    int normalPercent, finalPercent;
    cin >> nums >> normalPercent >> finalPercent;
    vector<Student> stuList;
    while(nums--) {
        Student temp;
        cin >> temp.finalScore;
        stuList.push_back(temp);
    }
    sort(stuList.begin(), stuList.end(), compareDown);
    int lastNormalScore = 100;
    int lastFinalScore = stuList[0].finalScore;
    int passNums = 0;
    for(int i = 0; i < stuList.size(); ++i) {
        if(stuList[i].finalScore < lastFinalScore) {
            --lastNormalScore;
            stuList[i].normalScore = lastNormalScore;
            lastFinalScore = stuList[i].finalScore;
        }
        else {
            stuList[i].normalScore = lastNormalScore;
        }
        if((stuList[i].normalScore * normalPercent + stuList[i].finalScore * finalPercent) >= 6000) {
            ++passNums;
        }
    }
    cout << passNums << endl;

    return 0;
}