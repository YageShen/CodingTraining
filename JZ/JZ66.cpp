class Solution {
public:
    int sumOfBits(int num) {
        int ret = 0;
        while(num > 0) {
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
    void dfs(int rows, int cols, int r, int c, vector<vector<bool>>& vis, int threshold, int& ret) {
        if(r < 0 || r >= rows || c < 0 || c >= cols || vis[r][c]) {
            return;
        }
        if(sumOfBits(r) + sumOfBits(c) > threshold) {
            vis[r][c] = true;
            return;
        }
        vis[r][c] = true;
        ++ret;
        dfs(rows, cols, r + 1, c, vis, threshold, ret);
        dfs(rows, cols, r - 1, c, vis, threshold, ret);
        dfs(rows, cols, r, c + 1, vis, threshold, ret);
        dfs(rows, cols, r, c - 1, vis, threshold, ret);
    }
    
    int movingCount(int threshold, int rows, int cols) {
        if(threshold == 0) return 1;
        int ret = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        dfs(rows, cols, 0, 0, vis, threshold, ret);
        return ret;
    }
};