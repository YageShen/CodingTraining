class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(auto n : nums) 
            nums_set.insert(n);
        int maxLength = 0;
        int currentNum, currentLen;
        for(auto n : nums_set) {
            if(!nums_set.count(n-1)) {
                currentNum = n;
                currentLen = 1;
                while(nums_set.count(currentNum+1)) {
                    currentLen++;
                    currentNum++;
                }
                maxLength = max(maxLength, currentLen);
            }
        }
        return maxLength;
    }
};