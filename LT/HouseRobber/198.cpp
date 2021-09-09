class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_i1 = 0, dp_i2 = 0;
        int dp_i;
        for(int i = nums.size() - 1; i >= 0; --i) {
            dp_i = max(dp_i1, nums[i] + dp_i2);
            dp_i2 = dp_i1;
            dp_i1 = dp_i;
        }
        return dp_i;
    }
};