#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct corpse{
    int dist;
    int speed;
};

static bool compareUp(const corpse &c1, const corpse &c2)
{
    return (c1.dist - c1.speed) < (c2.dist - c2.speed);
}

int maxKillNum(vector<corpse>& corList, int m) {
    int n = corList.size();
    if(m >= n)
        return n;
    int left = m, right = n - 1;
    while(left <= right) {
        for(int i = left; i <= right; ++i) {
            corList[i].dist -= corList[i].speed;
            if(corList[i].dist <= 0) {
                return left;
            }
        }
        sort(corList.begin()+left, corList.end(), compareUp);
        ++left;
    }
    return left;
}

int main() {
    string line1, line2;
    int m;
    getline(cin, line1);
    getline(cin, line2);
    cin >> m;
    vector<int> dist;
    vector<int> speed;
    string seg;
    istringstream iss1(line1);
    while(getline(iss1, seg, ',')) {
        dist.push_back(stoi(seg));
    }
    istringstream iss2(line2);
    while(getline(iss2, seg, ',')) {
        speed.push_back(stoi(seg));
    }
    int n = dist.size();
    vector<corpse> corList(n);
    for(int i = 0; i < n; ++i) {
        corList[i].dist = dist[i];
        corList[i].speed = speed[i];
    }
    sort(corList.begin(), corList.end(), compareUp);
    int num = maxKillNum(corList, m);
    cout << num << endl;
    return 0;
}