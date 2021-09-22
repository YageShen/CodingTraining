class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;
        while(true) {
            for(int i = l; i <= r; ++i) {
                ret.push_back(matrix[t][i]);
            }
            if(++t > b) break;
            for(int i = t; i <= b; ++i) {
                ret.push_back(matrix[i][r]);
            }
            if(--r < l) break;
            for(int i = r; i >= l; --i) {
                ret.push_back(matrix[b][i]);
            }
            if(--b < t) break;
            for(int i = b; i >= t; --i) {
                ret.push_back(matrix[i][l]);
            }
            if(++l > r) break;
        }
        return ret;
    }
};