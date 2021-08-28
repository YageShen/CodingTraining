class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool dfs(vector<vector<char> >& matrix, int r, int c, string& word, int idx) {
        if(idx == word.size())
            return true;
        if(r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size())
            return false;
        if(matrix[r][c] == word[idx]) {
            matrix[r][c] = ' ';
            ++idx;
            if(dfs(matrix, r+1, c, word, idx) || dfs(matrix, r-1, c, word, idx) 
                    || dfs(matrix, r, c+1, word, idx) || dfs(matrix, r, c-1, word, idx)) {
                return true;
            }
            else {
                --idx;
                matrix[r][c] = word[idx];
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == word[0]) {
                    if(dfs(matrix, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};