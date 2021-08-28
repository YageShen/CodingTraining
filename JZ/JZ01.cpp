class Solution {
public:
    bool Find(int target, vector<vector<int> > &array) {
        int row = array.size();
        int col = array[0].size();
        int r = 0, c = col - 1;
        while(r < row && c >= 0)
        {
            if(target > array[r][c])
                r++;
            else if(target < array[r][c])
                c--;
            else
                return true;
        }
        return false;
    }
};