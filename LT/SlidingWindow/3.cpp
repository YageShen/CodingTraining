class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int ret = 0;
        while (right < s.size()) {
            char c = s[right];
            ++right;
            ++window[c];
            while(window[c] > 1) {
                char cl = s[left];
                ++left;
                --window[cl];
            }
            ret = max(ret, right - left);
        }
        return ret;
    }
};