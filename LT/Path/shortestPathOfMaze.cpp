
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y): x(_x), y(_y) {}
};


class Solution {
public:
    int shortestPathBFS(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows == 1 && cols == 1)
            return 0;
        bool vis[rows][cols];
        memset(vis, false, sizeof(vis));
        queue<Point> q;
        q.emplace(0, 0);
        vis[0][0] = true;
        for(int step = 1; q.size() > 0; ++step) {
            int cnt = q.size();
            for(int i = 0; i < cnt; ++i) {
                Point p = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j) {
                    int nx = p.x + dir[j][0];
                    int ny = p.y + dir[j][1];
                    if(nx >= 0 && nx < rows && ny >=0 && ny < cols) {
                        if(grid[nx][ny] == 0 && !vis[nx][ny]) {
                            if(nx == rows - 1 && ny == cols - 1)
                                return step;
                            else {
                                q.emplace(nx, ny);
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
private:
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
};


int main() {
    vector<vector<int>> grid{{0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0}};
//     vector<vector<int>> grid{{0,0,0}, {1,1,0}};
    Solution sol;
    cout << sol.shortestPathBFS(grid) << endl;
    return 0;
}
