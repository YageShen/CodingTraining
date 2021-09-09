class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        return max(dp(nums, 0, len - 2), dp(nums, 1, len - 1));
    }
private:
    int dp(vector<int>& nums, int start, int end) {
        int dp_i2 = 0, dp_i1 = 0;
        int dp_i = 0;
        for(int i = end; i >= start; --i) {
            dp_i = max(dp_i1, nums[i] + dp_i2);
            dp_i2 = dp_i1;
            dp_i1 = dp_i;
        }
        return dp_i;
    }
};