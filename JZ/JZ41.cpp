class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int tempSum = 3;
        for(int l = 1, r = 2; l < r; ) {
            if(tempSum == sum) {
                vector<int> tempVec(r - l + 1);
                for(int i = l; i <= r; ++i) {
                    tempVec[i-l] = i;
                }
                ret.emplace_back(tempVec);
                tempSum -= (l++);
                tempSum += (++r);
                tempSum -= (l++);
            }
            else if(tempSum > sum) {
                tempSum -= (l++);
            }
            else {
                tempSum += (++r);
            }
        }
        return ret;
    }
};