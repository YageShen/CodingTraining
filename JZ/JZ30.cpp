class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size()+1, 0);
        int ret = array[0];
        for(int i(1); i <= array.size(); ++i) {
            dp[i] = max(array[i-1], dp[i-1]+array[i-1]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};